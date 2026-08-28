import java.util.*;

abstract class RequestHandler
{
    protected RequestHandler nextRequestHandler;
    
    
    public void setNextHandler(RequestHandler requestHandler){
        this.nextRequestHandler = requestHandler;
    }
    
    public abstract void handleRequest();
}

class RequestHandler1 extends RequestHandler
{
    
    @Override
    public void handleRequest()
    {
        return;
    }
}

class RequestHandler2 extends RequestHandler
{
    
    @Override
    public void handleRequest()
    {
        return;
    }
}

class ChainOfResponsibilityClient
{
    public static void main(String[] args)
    {
        return;
    }
}
