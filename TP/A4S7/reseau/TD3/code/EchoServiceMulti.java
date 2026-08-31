import java.io.*;
import java.net.*;

class EchoService extends Thread {

	Socket s;

	public EchoService( Socket s ) {
		System.out.println( "client connected" );
		this.s = s;
		start();
	}

	public void run() {
		try {
			BufferedReader input = new BufferedReader( new InputStreamReader( s.getInputStream() ) );
			PrintStream output = new PrintStream( s.getOutputStream() );
			String line = input.readLine();
			while( !line.equals( "" ) ) {
				output.println( line );
				line = input.readLine();
			}
			s.close();
			System.out.println( "client diconnected" );
		} catch( Exception e ) {}
	}
}

public class EchoServiceMulti {
	public static void main( String[] args ) throws Exception {
		int port = 1234;

		if( args.length == 1 )
			port = Integer.parseInt( args[0] );

		ServerSocket ss = new ServerSocket( port );
		System.out.println( "listening on TCP port #" + port + "..." );

		while( true ) {
			Socket s = ss.accept();
			new EchoService( s );
		}
	}
}