import java.io.*;
import java.net.*;
import java.util.*;


class DaytimeService extends Thread {


	Socket s;


	public DaytimeService( Socket s ) {
		System.out.println( "client connected" );
		this.s = s;
		start();
	}


	public void run() {
		try {
			PrintStream output = new PrintStream( s.getOutputStream() );
			output.println( new Date() );
			s.close();
			System.out.println( "client diconnected" );
		} catch( Exception e ) {}
	}


}


public class DaytimeServiceMulti {


	public static void main( String[] args ) throws Exception {
		int port = 1234;

		if( args.length == 1 )
			port = Integer.parseInt( args[0] );

		ServerSocket ss = new ServerSocket( port );
		System.out.println( "listening on TCP port #" + port + "..." );

		while( true ) {
			Socket s = ss.accept();
			new DaytimeService( s );
		}
	}


}

