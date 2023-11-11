
public class TreZeri
{
    public static boolean scan(String s)
    {
	int state = 0;
	int i = 0;

	while (state >= 0 && i < s.length()) {
	    final char ch = s.charAt(i++);
	    
	    boolean numbers = ch >= '0' && ch <= '9';
	    boolean sign = ch == '+' || ch == '-';
	    boolean e = ch == 'e';
	    boolean dot = ch == '.';
	    boolean all = numbers || sign || e;

	    switch (state) {
	    case 0:
		if(sign)
		    state = 1;
		else if(numbers)
		    state = 2;
		else if(dot)
			state = 3;
		else if(e)
			state = 4;
		else
		    state = -1;
		break;

	    case 1:
		if (numbers)
		    state = 2;
		else if (dot)
		    state = 3;
		else if(sign)
		    state = 5;
		else
			state = -1;
		break;

	    case 2:
		if (numbers)
		    state = 2;
		else if (e)
		    state = 4;
		else if(dot)
			state = 3;
		else if(sign)
			state = 5; 
		else
		    state = -1;
		break;

	    case 3:
		if (numbers)
		    state = 2;
		else if(dot)
		    state = 5;
		else
			state = -1;
		break;
	     case 4:
	     	if(sign)
	     		state = 1;
	     	else if(numbers)
	     		state = 2;
	     	else if(e)
	     		state = 5;
	     	else
	     		state = -1;
	     	break;
	     case 5:
	     	if(all)
	     		state = 5;
	     	else
	     		state = -1;
	    }
	}
	return state == 2;
    }

    public static void main(String[] args)
    {
	System.out.println(scan(args[0]) ? "OK" : "NOPE");
    }
}

