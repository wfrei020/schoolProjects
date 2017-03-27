
public class SudokoNumberCheck {
private int[] sudoko;
private boolean puzzleCorrect = true;
	private CheckSudoko[] tests = new CheckSudoko[27];
private int failID = 0;
	
	//tests 0-8 : columns,
	//tests 9-17 : rows,
	// tests 18-26 : squares
	public SudokoNumberCheck(int[] sudoko){
		this.sudoko = sudoko;
	tests[0] =new CheckSudoko(new int[]{0,1,2,3,4,5,6,7,8} , sudoko);
	tests[1] =new CheckSudoko(new int[]{9,10,11,12,13,14,15,16,17} , sudoko);
	tests[2] =new CheckSudoko(new int[]{18,19,20,21,22,23,24,25,26} , sudoko);
	tests[3] =new CheckSudoko(new int[]{27,28,29,30,31,32,33,34,35} , sudoko);
	tests[4] =new CheckSudoko(new int[]{36,37,38,39,40,41,42,43,44} , sudoko);
	tests[5] =new CheckSudoko(new int[]{45,46,47,48,49,50,51,52,53} , sudoko);
	tests[6] =new CheckSudoko(new int[]{54,55,56,57,58,59,60,61,62} , sudoko);
	tests[7] =new CheckSudoko(new int[]{63,64,65,66,67,68,69,70,71} , sudoko);
	tests[8] =new CheckSudoko(new int[]{72,73,74,75,76,77,78,79,80} , sudoko);
	tests[9] =new CheckSudoko(new int[]{0,9,18,27,36,45,54,63,72} , sudoko);
	tests[10] =new CheckSudoko(new int[]{1,10,19,28,37,46,55,64,73} , sudoko);
	tests[11] =new CheckSudoko(new int[]{2,11,20,29,38,47,56,65,74} , sudoko);
	tests[12] =new CheckSudoko(new int[]{3,12,21,30,39,48,57,66,75} , sudoko);
	tests[13] =new CheckSudoko(new int[]{4,13,22,31,40,49,58,67,76} , sudoko);
	tests[14] =new CheckSudoko(new int[]{5,14,23,32,41,50,59,68,77} , sudoko);
	tests[15] =new CheckSudoko(new int[]{6,15,24,33,42,51,60,69,78} , sudoko);
	tests[16] =new CheckSudoko(new int[]{7,16,25,34,43,52,61,70,79} , sudoko);
	tests[17] =new CheckSudoko(new int[]{8,17,26,35,44,53,62,71,80} , sudoko);
	tests[18] =new CheckSudoko(new int[]{0,1,2,9,10,11,18,19,20} , sudoko);
	tests[19] =new CheckSudoko(new int[]{3,4,5,12,13,14,21,22,23} , sudoko);
	tests[20] =new CheckSudoko(new int[]{6,7,8,15,16,17,24,25,26} , sudoko);
	tests[21] =new CheckSudoko(new int[]{27,28,29,36,37,38,45,46,47} , sudoko);
	tests[22] =new CheckSudoko(new int[]{30,31,32,39,40,41,48,49,50} , sudoko);
	tests[23] =new CheckSudoko(new int[]{33,34,35,42,43,44,51,52,53} , sudoko);
	tests[24] =new CheckSudoko(new int[]{54,55,56,63,64,65,72,73,74} , sudoko);
	tests[25] =new CheckSudoko(new int[]{57,58,59,66,67,68,75,76,77} , sudoko);
	tests[26] =new CheckSudoko(new int[]{60,61,62,69,70,71,78,79,80} , sudoko);

	
	int i= 0;
	while(i<tests.length){
	new Thread(tests[i]).start();
	i++;
	}
	i = 0;
	while(i < tests.length){
		while(true){
			if(tests[i].iscomputationDone()){if(!tests[i].getisCorrect()){puzzleCorrect = false;
			failID = i;
			break;}
			break;}
		if(puzzleCorrect == false){break;}
		}
		i++;
	}
	
	
	
	}
	
	public boolean getCorrectness(){return puzzleCorrect;}
	public int getFailID(){return failID;}
	
	
	public static void main(String[] args){
		System.out.println("Currently Testing the following Sudoko Puzzle\n");
		int[] sudoko = {6,2,4,5,3,9,1,8,7,5,1,9,7,2,8,6,3,4,8,3,7,6,1,4,2,9,5,1,4,3,8,6,5,7,2,9,9,5,8,2,4,7,3,6,1,7,6,2,3,9,1,4,5,8,3,7,1,9,5,6,8,4,2,4,9,6,1,8,2,5,7,3,2,8,5,4,7,3,9,1,6};
		int i = 0;
		while(i<8){
		System.out.print(sudoko[i]+" ");
		i++;
		}
		System.out.println(sudoko[i]);
		i++;
		while(i<17){
		System.out.print(sudoko[i]+" ");
		i++;
		}
		System.out.println(sudoko[i]);
		i++;
		while(i<26){
		System.out.print(sudoko[i]+" ");
		i++;
		}
		System.out.println(sudoko[i]);
		i++;
		while(i<35){
		System.out.print(sudoko[i]+" ");
		i++;
		}
		System.out.println(sudoko[i]);
		i++;
		while(i<44){
		System.out.print(sudoko[i]+" ");
		i++;
		}
		System.out.println(sudoko[i]);
		i++;
		while(i<53){
		System.out.print(sudoko[i]+" ");
		i++;
		}
		System.out.println(sudoko[i]);
		i++;
		while(i<62){
		System.out.print(sudoko[i]+" ");
		i++;
		}
		System.out.println(sudoko[i]);
		i++;
		while(i<71){
		System.out.print(sudoko[i]+" ");
		i++;
		}
		System.out.println(sudoko[i]);
		i++;
		while(i<80){
		System.out.print(sudoko[i]+" ");
		i++;
		}
		System.out.println(sudoko[i]);
		
	SudokoNumberCheck sudokoGame = 	new SudokoNumberCheck(sudoko);
		
		if(sudokoGame.getCorrectness()){
			System.out.println("\nThe puzzle is correct");
		}
		else{
			System.out.print("Fail is in ");
			if(sudokoGame.getFailID() == 0){System.out.println("column 1");}
			else if(sudokoGame.getFailID() == 1){System.out.println("column 2");}
			else if(sudokoGame.getFailID() == 2){System.out.println("column 3");}
			else if(sudokoGame.getFailID() == 3){System.out.println("column 4");}
			else if(sudokoGame.getFailID() == 4){System.out.println("column 5");}
			else if(sudokoGame.getFailID() == 5){System.out.println("column 6");}
			else if(sudokoGame.getFailID() == 6){System.out.println("column 7");}
			else if(sudokoGame.getFailID() == 7){System.out.println("column 8");}
			else if(sudokoGame.getFailID() == 8){System.out.println("column 9");}
			else if(sudokoGame.getFailID() == 9){System.out.println("row 1");}
			else if(sudokoGame.getFailID() == 10){System.out.println("row 2");}
			else if(sudokoGame.getFailID() == 11){System.out.println("row 3");}
			else if(sudokoGame.getFailID() == 12){System.out.println("row 4");}
			else if(sudokoGame.getFailID() == 13){System.out.println("row 5");}
			else if(sudokoGame.getFailID() == 14){System.out.println("row 6");}
			else if(sudokoGame.getFailID() == 15){System.out.println("row 7");}
			else if(sudokoGame.getFailID() == 16){System.out.println("row 8");}
			else if(sudokoGame.getFailID() == 17){System.out.println("row 9");}
			else if(sudokoGame.getFailID() == 18){System.out.println("Top left box");}
			else if(sudokoGame.getFailID() == 19){System.out.println("Top Middle box");}
			else if(sudokoGame.getFailID() == 20){System.out.println("Top right box");}
			else if(sudokoGame.getFailID() == 21){System.out.println("Centre left box");}
			else if(sudokoGame.getFailID() == 22){System.out.println("Centre centre box");}
			else if(sudokoGame.getFailID() == 23){System.out.println("Center right box");}
			else if(sudokoGame.getFailID() == 24){System.out.println("Bottom left box");}
			else if(sudokoGame.getFailID() == 25){System.out.println("Bottom centre box");}
			else if(sudokoGame.getFailID() == 26){System.out.println("Bottom right box");}
			
			
		}
	}
}
