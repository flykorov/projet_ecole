import java.io.*;
import java.net.*;
import java.util.*;

public class DaytimeServiceMono {
	public static void main( String[] args ) throws Exception {
		int port = 1234;

		if( args.length == 1 )
			port = Integer.parseInt( args[0] );

		ServerSocket ss = new ServerSocket( port );
		System.out.println( "listening on TCP port #" + port + "..." );

		while( true ) {
			Socket s = ss.accept();
			System.out.println( "client connected" );
			PrintStream output = new PrintStream( s.getOutputStream() );
			output.println( new Date() );
			s.close();
			System.out.println( "client diconnected" );
		}
	}
}
