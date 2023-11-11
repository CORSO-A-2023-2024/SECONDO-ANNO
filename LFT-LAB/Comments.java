
public class Comments
{
    public static boolean scan(String s)
    {
	int state = 0;
	int i = 0;

	while (state >= 0 && i < s.length()) {
	    final char ch = s.charAt(i++);
	    
	    boolean slash = ch == '/';
	    boolean letter = ch == 'a';
	    boolean star = ch == '*';
	    boolean alfabet = slash || letter || star;

	    switch (state) {
	    case 0:
		if(slash)
		    state = 1;
		else
		    state = -1;
		break;

	    case 1:
		if(star)
		    state = 2;
		else
			state = -1;
		break;

	    case 2:
		if (slash || letter)
		    state = 3;
		else if(star)
			state = 4;
		else
		    state = -1;
		break;

	    case 3:
		if(letter || slash)
		    state = 3;
		else if(star)
		    state = 4;
		else
			state = -1;
		break;
	     case 4:
	     	if(letter)
	     		state = 3;
	     	else if(slash)
	     		state = 5;
	     	else if(star)
	     		state = 4;
	     	else
	     		state = -1;
	     	break;
	     case 5:
	     	if(alfabet)
	     		state = 3;
	     	else
	     		state = -1;
	     	break;
	    }
	}
	return state == 5;
    }

    public static void main(String[] args)
    {
 	System.out.println(scan(args[0]) ? "OK" : "NOPE");
    }
}

