import java.util.*;
import java.lang.*;
import java.io.*;

interface ITarget
{
    
}

class TargetClass implements ITarget
{
    private Source source;
}

class Source
{
    
}


class AdaptorClient
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
        ITarget taregt = new TargetClass();
        
	}
}
