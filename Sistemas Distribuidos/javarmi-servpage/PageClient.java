// Programa Java com RMI
// PageClient.java - Classe usuaria de paginas
//-------------------------------------------------------------

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class PageClient {
  private PageClient() {}
  // Metodo principal
  public static void main (String[] args) {
    int pagina;

    // Especifica o nome do servidor e do objeto para obter um stub para acessar o objeto servidor
    String host = (args.length < 1) ? null : args[0];
    try {
       Registry registry = LocateRegistry.getRegistry(host);
       Page stub = (Page) registry.lookup("Page");
       for(;;) {
          Thread.sleep(500);
          // Requisita uma pagina
          System.out.println ("vou pedir uma pagina ");
          pagina = stub.request();
          System.out.println ("obtive pagina " + pagina);
          // Libera uma pagina
          Thread.sleep(500);
          System.out.println ("vou liberar " + pagina);
          stub.release(pagina);
       }
    } catch (Exception e) {
       System.err.println("Erro cliente: " + e.toString());
       e.printStackTrace();
    }
  }
}
