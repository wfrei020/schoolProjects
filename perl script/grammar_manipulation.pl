# CSI 3120 Assignment 3 Solution
# Student Name: Walter Freire
# Student Number: 6399015
# Student Email: wfrei020@uottawa.ca
#========================================================================================================
#Some defintions to keep track and count, input/outfile names
#========================================================================================================
$current_Production_Line = 0;
$correctGrammar = 1;
$in = $ARGV[0];
$out = $ARGV[1];
#========================================================================================================
#Check for input file errors
#========================================================================================================
unless(defined $in){die "Error with $0"}
#========================================================================================================
# creating output if it does not exist, if the input is correct it will get deleted later on
#========================================================================================================
unless(defined $out){
$out = $in;
$out =~ s/(\.txt)$/_out.txt/;}
unless($out =~ /(\.txt)$/){$out = $out. '.txt';}
unless(open INPUT, "<$in"){die "cannot open '$in' : $!";}
unless(open OUTPUT , ">$out"){die " cannot write to '$out' : $!";}
#========================================================================================================
#main loop which reads line by line and collects data
#========================================================================================================
while($production_line = <INPUT>){
$current_Production_Line++;
$has_Left_Factoring = 0;
$has_Left_Recursion = 0;
@split_line = split (/\s+/, $production_line);
if($split_line[0] =~ /[A-Z].*/){
	if( $split_line[1] =~ /-*>/){
#========================================================================================================
#Checking for right side
#========================================================================================================
		if( $split_line[2] eq ''){push(@missingProduction, $current_Production_Line);$correctGrammar = 0;}
		else{
#========================================================================================================
#check for left recursion and left factoring
		
			$has_Left_Recursion = CheckLeftRecursion(@split_line);
			$has_Left_Factoring = CheckLeftFactoring(@split_line);
#========================================================================================================
#if it has left recursion call remove algorithm and then check if new lines have left factoring
#if the new lines generated do have left factorng simply remove them using the left factoring algorithm
#========================================================================================================
			if($has_Left_Recursion){
				$correctGrammar = 0;
				@newLines = RemoveLeftRecursion(@split_line);
				if(CheckLeftFactoring(split (/\s+/, $newLines[0]))){
					@newLines1= RemoveLeftFactoring(split (/\s+/, $newLines[0]));
					print OUTPUT $newLines1[0];
					print OUTPUT "\n";
					print OUTPUT $newLines1[1];}
				else{print OUTPUT $newLines[0];
					print OUTPUT "\n";}
				if(CheckLeftFactoring(split (/\s+/, $newLines[1]))){
					@newLines2 = RemoveLeftFactoring(split (/\s+/, $newLines[1]));
					print OUTPUT $newLines2[0];
					print OUTPUT "\n";
					print OUTPUT $newLines2[1];}
				else{print OUTPUT $newLines[1];
				print OUTPUT "\n";}}
#========================================================================================================
#if there is no left recursion and there is left factoring simply call the remove left factoring algorithm
#========================================================================================================
			elsif( not $has_Left_Recursion and $has_Left_Factoring){
				$correctGrammar = 0;
				@newLines2 = RemoveLeftFactoring(@split_line);
				print OUTPUT $newLines2[0];
				print OUTPUT "\n";
				print OUTPUT $newLines2[1];}
#========================================================================================================
#if there are no problems with the production line simply print in the output
#========================================================================================================
			else{print OUTPUT $production_line;}}}
	else{push(@missing_Arrow , $current_Production_Line);$correctGrammar = 0;}}
else{push(@left_Terminal_found,$split_line[0]);$correctGrammar = 0;}}
$printedInvalid = 0;
#========================================================================================================
#checks if there are any missing arrows queue
#========================================================================================================
if(defined $missing_Arrow[0]){
	$printedInvalid = 1;
	print "Invalid Grammar in input file: $in\n";
	for($i = 0 ; $i < scalar @missing_Arrow ; $i++){
		print "Missing Arrow in line: $missing_Arrow[$i]\n";}
	close OUTPUT;
	unlink $out;}
#========================================================================================================
#checks if there are any terminals in the left side queue
#========================================================================================================
if(defined $left_Terminal_found[0]){
	unless($printedInvalid == 1){ print "Invalid Grammar in input file: $in\n";
		$printedInvalid = 1;
		close OUTPUT;
		unlink $out;}
	for($i = 0 ; $i < scalar @left_Terminal_found ; $i++){
		print "Terminal '$left_Terminal_found[$i]'  found in the left-hand of  a production\n";}
	close OUTPUT;
	unlink $out;}
#========================================================================================================
#checks if there are any missing production in the right side queue
#========================================================================================================
if(defined $missingProduction[0]){
	unless($printedInvalid == 1){print"Invalid Grammar in input file: $in\n";
		$printedInvalid = 1;
		close OUTPUT;
		unlink $out;}
	for($i = 0 ; $i < scalar @missingProduction ; $i++){
		print "Missing in line '$missingProduction[$i]'  production in the right side\n";}}
#========================================================================================================
#checks if there are any indirect left recursion in the queue
#========================================================================================================
 if(defined $indirectLeft[0]){
	print "warning: indirect left recursion detected  in non-Terminals: ";
	for($i = 0 ; $i < scalar @indirectLeft ; $i++){
		print "$indirectLeft[$i] ";}
	print "\n";}
#========================================================================================================
#if grammar is correct delete the out file created and keep the original file
#========================================================================================================
unless($correctGrammar == 0){
	print "Input Grammar OK\n";
	close OUTPUT;
	unlink $out;}
#========================================================================================================
#Algorithm to check if left factoring Exist
#========================================================================================================

sub CheckLeftFactoring(){
my @currentLine = @_;
undef @rightSide;
undef @result;
$leftFactoring = 0;
for($i = 2 ; $i < scalar @currentLine ; $i++){push( @rightSide , $currentLine[$i]);}
$rightsideLine = join(' ', @rightSide);
@singleElements = split(/\s+\|\s+/, $rightsideLine);
$i = 0;
while($i < scalar @singleElements){
	@firstElement = split (/\s+/, $singleElements[$i]);
	if($firstElement[0] =~ /[a-z].*/){
		$j = $i + 1;
		while ($j < scalar @singleElements ){
			@otherFirstElement = split (/\s+/, $singleElements[$j]);
			if($otherFirstElement[0] =~ /[a-z].*/ and $otherFirstElement[0] eq $firstElement[0]){$leftFactoring = true;
				last;}
		$j++;}}
	if($leftFactoring){last;}
	$i++;}
return $leftFactoring;}
#========================================================================================================
#algorithm to check if left recursion exist
#========================================================================================================
sub CheckLeftRecursion(){
my @currentLine = @_;
$leftRecursion = 0;
undef @rightSide;
	for($i = 2 ; $i < scalar @currentLine ; $i++){push( @rightSide , $currentLine[$i]);}
	$rightsideLine = join(' ', @rightSide);
	@singleElements = split(/\s+\|\s+/, $rightsideLine);
	$i = 0;
	while($i < scalar @singleElements){
		@firstElement = split (/\s+/, $singleElements[$i]);
		if($firstElement[0] =~ /[A-Z].*/ and ($firstElement[0] eq $currentLine[0] )){
			$leftRecursion = true;}
		if( $firstElement[scalar @firstElement - 1] eq $currentLine[0]){push(@indirectLeft, $currentLine[0]);}
		$i++;}
return $leftRecursion;}
#========================================================================================================
#algorithm to remove left recursion
#========================================================================================================

sub RemoveLeftRecursion(){

my @currentLine = @_;
$leftRecursion = 0;
undef @rightSide;
for($i = 2 ; $i < scalar @currentLine ; $i++){push( @rightSide , $currentLine[$i]);}
 $rightsideLine = join(' ', @rightSide);
 @singleElements = split(/\s+\|\s+/, $rightsideLine);
 $i = 0;
 $NT = $currentLine[0]. ' -> ';
 $NTPrime = $currentLine[0]. 'Prime -> ';
while($i < scalar @singleElements){
	$l = 1;
	$l++;
	@firstElement = split (/\s+/, $singleElements[$i]);
	if($firstElement[0] =~ /[A-Z].*/ and ($firstElement[0] eq $currentLine[0] )){
		for($j = 1 ; $j < scalar @firstElement ; $j++){
		$NTPrime = $NTPrime. $firstElement[$j]. ' ';}
		$NTPrime = $NTPrime.$currentLine[0]. 'Prime | ';}
	else{
		for($j = 0 ; $j < scalar @firstElement ; $j++){
		$NT = $NT.$firstElement[$j]. ' ';}
		if($i  == scalar @currentLine - 1){
		$NT = $NT.$currentLine[0]. 'Prime';}
		else{ $NT = $NT.$currentLine[0]. 'Prime | ';}}
	$i++;}
$NTPrime = $NTPrime. ' epsilon';
$NT =~ s/ (\|\s+)$//;
push(@result, $NT);
push(@result, $NTPrime);
return @result;}
#========================================================================================================
#algorithm to remove left factoring
#========================================================================================================

sub RemoveLeftFactoring(){
my @currentLine = @_;
$leftfactoring = 0;
undef @rightSide;
undef @result;
for($i = 2 ; $i < scalar @currentLine ; $i++){push( @rightSide , $currentLine[$i]);}
$rightsideLine = join(' ', @rightSide);
@singleElements = split(/\s+\|\s+/, $rightsideLine);
$i = 1;
$NT = $currentLine[0].' -> ';
$NTPrimePrime = $currentLine[0].'Prime -> ';
#assuming we have the repeated elements a list of repeted elements
@firstElement = split (/\s+/, $singleElements[0]);
$repetedElem = $firstElement[0];
$NT = $NT. $firstElement[0]. ' '.$currentLine[0]. 'Prime | ';
for($k = 1 ; $k < scalar @firstElement ; $k++){
	if($k == scalar @firstElement - 1){ $NTPrimePrime = $NTPrimePrime. $firstElement[$k]. ' | ';}
	else{ $NTPrimePrime = $NTPrimePrime. $firstElement[$k]. ' ';}}	
while($i < scalar @singleElements){
	@firstElement = split (/\s+/, $singleElements[$i]);
	if($firstElement[0] =~ /[a-z].*/ and $firstElement[0] eq $repetedElem){
		for($k = 1 ; $k < scalar @firstElement ; $k++){
			if($k == scalar @firstElement - 1 and $i < scalar @singleElements - 1){ $NTPrimePrime = $NTPrimePrime. $firstElement[$k]. ' | ';}
			elsif($k == scalar @firstElement - 1 and $i == scalar @singleElements - 1){$NTPrimePrime = $NTPrimePrime. $firstElement[$k];}
			else{ $NTPrimePrime = $NTPrimePrime. $firstElement[$k]. ' ';}}}	
	else{
		for($j = 0 ; $j < scalar @firstElement ; $j++){
			$NT = $NT. $firstElement[$j]. ' ';}
		if( $i < scalar $singleElements - 1){$NT = $NT. ' | '}}
	$i++;}
$NTPrimePrime =~ s/ (\|\s+)$//;
$NT =~ s/ (\|\s+)$//;
push(@result, $NT);
push(@result, $NTPrimePrime);
return @result;}
#========================================================================================================
#EOF
#========================================================================================================