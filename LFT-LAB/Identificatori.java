public class Identificatori{
	public static boolean scan(String s){
		int state = 0;
		int i = 0;

		while (state >= 0 && i < s.length()) {
		    final char ch = s.charAt(i++);
		    boolean lower = ch >= 'a' && ch <= 'z';
		    boolean capital = ch >= 'A' && ch <= 'Z';
		    boolean numbers = ch >= '0' && ch <= '9';
		    switch(state){
		    	case 0:
		    		if(ch == '_'){
		    			state = 1;
		    		}else if(numbers){
		    			state = 3;
		    		}else if( capital || lower){
		    			state = 2;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 1:
		    		if(ch == '_'){
		    			state = 1;
		    		}else if(numbers || capital || lower){
		    			state = 2;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 2:
		    		if(numbers || capital || lower || ch == '_'){
		    			state = 2;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    	case 3:
		    		if(numbers || capital || lower || ch == '_'){
		    			state = 3;
		    		}else{
		    			state = -1;
		    		}
		    		break;
		    }
		}
		return state == 2;
    }

    public static void main(String[] args)
    {
	System.out.println(scan(args[0]) ? "OK" : "NOPE");
    }
}
