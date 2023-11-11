public class Matricole{
	public static boolean scan(String s){
		int state = 0;
		int i = 0;

		while (state >= 0 && state <= 7 && i < s.length()) {
		    final char ch = s.charAt(i++);
		    boolean lower = ch >= 'a' && ch <= 'z';
		    boolean capital = ch >= 'A' && ch <= 'Z';
		    boolean capitalT1_T2 = ch >= 'A' && ch <= 'K';
		    boolean capitalT3_T4 = ch >= 'L' && ch <= 'Z';
		    boolean latin = lower || capital;
		    boolean numbers = ch >= '0' && ch <= '9';
		    boolean isOdd = numbers && (ch % 2 != 0);
		    switch(state){
		    	case 0:
		    		if(isOdd){
		    			state = 2;  
		    		}else if(numbers && !isOdd){
		    			state = 1;
		    		}else if(capital || lower){
		    			state = 3;		
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 1:
		    		if(isOdd){
		    			state = 2;
		    		}else if(numbers && !isOdd){
		    			state = 1;
		    		}else if(capitalT1_T2){
		    			state = 4;
		    		}else if(capitalT3_T4){
		    			state = 5;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 2:
		    		if(isOdd){
		    			state = 2;
		    		}else if(numbers && !isOdd){
		    			state = 1;
		    		}else if(capitalT1_T2){
		    			state = 6;
		    		}else if(capitalT3_T4){
		    			state = 7;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 3:
		    		if(numbers || latin){
		    			state = 3;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 4: 
		    		if(latin){
		    			state = 4;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 5: 
		    		if(latin){
		    			state = 5;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 6: 
		    		if(latin){
		    			state = 6;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 7: 
		    		if(latin){
		    			state = 7;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    }
		}
		return state >= 4;
    }

    public static void main(String[] args)
    {
	System.out.println(scan(args[0]) ? "OK" : "NOPE");
    }
}
