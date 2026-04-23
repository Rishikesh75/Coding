
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;


class MyThread extends  Thread{
    private int id;
    
    public MyThread(int id){
        this.id = id;
    }
    @Override
    public void run()
    {
        try {
            Thread.sleep(id  == 1 ? 100 : 200);
        } catch (InterruptedException ex) {
            System.getLogger(MyThread.class.getName()).log(System.Logger.Level.ERROR, (String) null, ex);
        }
;
        System.out.printf("This is the Custom Thread...%d\n",id);
    }
}

class MyRunnable implements Runnable{

    private int id = 1;
    
    public MyRunnable(int id){
        this.id = id;
    }
    @Override
    public void run(){
        System.out.printf("this is a runnable implements Thread:%d %s\n",id,Thread.currentThread().getName());
    }
}

class RunnableCallable implements  Runnable{

    private Callable<String> task;

    public RunnableCallable(Callable<String> task){
        this.task = task; 
    }

    @Override
    public void run(){
        
        try {
            String result = task.call();
            System.out.println("Result:"+result);
        }
        
        catch (Exception e) {
            
        }
        return;
    }
}
class MyCallable implements Callable<String>{

    @Override
    public String call(){
        return "this is callable is implement";
    }
}


class sample{

    private Object obj;
    public synchronized void display(){


        return;
    }

    public void customDisplay()
    {
        synchronized (obj) {
            
            try {
                      obj.wait();
            } catch (Exception e) {
            }
      

            obj.notify();

            obj.notifyAll();
            
        }
    }
}
public class ThreadJava{

    
    public static void main(String[] args){

        MyThread t1 = new MyThread(1);
        MyThread t2 = new MyThread(2);
        Thread t3 = new Thread(new MyRunnable(3));
        t3.setName("Runnable Thread");
        t1.start();
        t2.start();
        t3.start();
        System.out.println("This is the Main Thread...");


        ExecutorService executorService = Executors.newFixedThreadPool(2);

        Future<String> future = executorService.submit(new MyCallable());

        try {
            String ans = future.get();
            System.out.println(ans);
        } catch (Exception e) {
        }
        
        executorService.shutdown();

        Thread t4 = new Thread(new RunnableCallable(new MyCallable()));
        t4.run();

    }
}