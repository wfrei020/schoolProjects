
public class CheckSudoko implements Runnable{
private int[] sudokodata;
private int[] index;
private int[] sudokoCheck = new int[9]; 
private boolean isCorrect = true;
private boolean computationDone = false;

	public CheckSudoko(int[] index, int[] sudokodata){
		this.sudokodata = sudokodata;
		this.index = index;
		int i = 0;
		while(i < 9){
		sudokoCheck[i] = 0;
		i++;
		}
	}
	
	public void run(){
		int i = 0;
		while(i < index.length){
			if(sudokoCheck[sudokodata[index[i]]-1] == 0){
				sudokoCheck[sudokodata[index[i]]-1] = 1;
				if(i == index.length -1){computationDone = true;}
				i++;
			}
			else{ isCorrect = false;
			computationDone = true;
			
				break;}
		}
	}
	
	public boolean iscomputationDone(){
		return computationDone;
	}
	public boolean getisCorrect(){
		return isCorrect;
	}





}
