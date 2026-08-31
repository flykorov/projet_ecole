import java.io.*;
import java.net.*;


class DiscardService extends Thread {

	Socket s;

	public DiscardService( Socket s ) {
		System.out.println( "client connected" );
		this.s = s;
		start();
	}

	public void run() {
		try {
			s.close();
			System.out.println( "client diconnected" );
		} catch( Exception e ) {}
	}
}


public class DiscardServiceMulti {

	public static void main( String[] args ) throws Exception {
		int port = 1234;

		if( args.length == 1 )
			port = Integer.parseInt( args[0] );

		ServerSocket ss = new ServerSocket( port );
		System.out.println( "listening on TCP port #" + port + "..." );

		while( true ) {
			Socket s = ss.accept();
			new DiscardService( s );
		}
	}
}
