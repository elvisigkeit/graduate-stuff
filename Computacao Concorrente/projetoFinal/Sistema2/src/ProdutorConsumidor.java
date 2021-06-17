
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.Arrays;
import java.util.LinkedList;

public class ProdutorConsumidor extends Thread{
	private LinkedList<String> buffer;

	ProdutorConsumidor (String nomeArquivo, LinkedList<String> buffer)
	{
		arq = Paths.get(nomeArquivo);
		this.buffer = buffer;
		this.fimPrograma = false;
	}

	public void escreveNoArquivo() {
		try {
			Files.write(arq, buffer, Charset.forName("UTF-8"), StandardOpenOption.APPEND);
		} catch (IOException e) {
			e.printStackTrace();
		}
		buffer.clear();
	}
	
	public void escreveNoBuffer (String entrada, int senha) {
		synchronized (this) {
			buffer.add(entrada);
			notify();
		}
	}
	
	public void termina() {
		synchronized (this) {
			fimPrograma = true;
			notify();
		}
	}
	
	public void run() {
		synchronized (this) {
			while(!fimPrograma) {
				try {
					wait();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				if(!buffer.isEmpty())
					escreveNoArquivo();
			}
		}
		
	}
	
	public boolean fimPrograma;
	private Path arq;
}
