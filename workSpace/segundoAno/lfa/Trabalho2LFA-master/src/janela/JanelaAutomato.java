package janela;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Locale;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.BevelBorder;

import arquivo.Leitura;
import estrutura.*;

import java.awt.ComponentOrientation;

public class JanelaAutomato{

	private static final long serialVersionUID = 1L;
	private JFrame janela;
	private JTextField campoCaminhoDoArquivo;
	private JTextField campoPalavraAProcessar;
	private JPanel painelSuperior;
	private JLabel labelCaminhoDoArquivo;
	private JButton botaoSelecionarArquivo;
	private JButton botaoOk;
	private JPanel painelCentral;
	private JLabel labelFita;
	private JLabel labelPilha;
	private JScrollPane scrollFita;
	private JTextArea textoFita;
	private JScrollPane scrollPilha;
	private JTextArea textoPilha;
	private JPanel painelInferior;
	private JLabel labelDigiteAPalavra;
	private JPanel painelBotoesInferiores;
	private JButton botaoProcessar;
	private JButton botaoReiniciar;
	private JanelaAutomato window;
	private JButton botaoLimparProcessamento;
	private Automato automato;
	private Leitura arquivo;
	
	// Construtor da classe JanelaAutomato
	public JanelaAutomato() {
		this.initialize();
	}
	
	//Setter da variavel automato
	public void setAutomato(Automato other) {
		this.automato = new Automato(other);
	}
	
	//Getter da variavel serialversionuid
	public static long getSerialversionuid() {
		return serialVersionUID;
	}
	
	/* Metodo que inicializa a tela
	 * Entrada: 	 Nenhuma
	 * Retorno: 	 Nenhum
	 * Pre-condicao: Nenhuma
	 * Pos-condicao: A tela e inicializada e mostrada ao usuario
	 */
	public void inicializarTela() {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					window = new JanelaAutomato();
					window.janela.setVisible(true);
					window.botaoOk.setEnabled(false);
					window.botaoProcessar.setEnabled(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/* Metodo que inicializa o conteudo dos frames
	 * Entrada: 	 Nenhuma
	 * Retorno: 	 Nenhum
	 * Pre-condicao: Nenhuma
	 * Pos-condicao: Os elementos do frame sao inicializados
	 */
	private void initialize() {
		//Definicoes da janela principal
		janela = new JFrame();
		janela.setLocale(new Locale("pt", "BR"));
		janela.getContentPane().setLocale(new Locale("pt", "BR"));
		janela.setIconImage(Toolkit.getDefaultToolkit().getImage(JanelaAutomato.class.getResource("/resource/processor.png")));
		janela.getContentPane().setBackground(Color.LIGHT_GRAY);
		GridBagLayout gridBagLayout = new GridBagLayout();
		gridBagLayout.columnWidths = new int[]{5, 0, 5, 0};
		gridBagLayout.rowHeights = new int[]{5, 75, 0, 75, 5, 0};
		gridBagLayout.columnWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
		gridBagLayout.rowWeights = new double[]{0.0, 0.0, 1.0, 0.0, 0.0, Double.MIN_VALUE};
		janela.getContentPane().setLayout(gridBagLayout);
		
		//Definicoes do painel superior
		painelSuperior = new JPanel();
		painelSuperior.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		painelSuperior.setBackground(Color.LIGHT_GRAY);
		GridBagConstraints gbc_painelSuperior = new GridBagConstraints();
		gbc_painelSuperior.insets = new Insets(0, 0, 5, 5);
		gbc_painelSuperior.fill = GridBagConstraints.BOTH;
		gbc_painelSuperior.gridx = 1;
		gbc_painelSuperior.gridy = 1;
		janela.getContentPane().add(painelSuperior, gbc_painelSuperior);
		GridBagLayout gbl_painelSuperior = new GridBagLayout();
		gbl_painelSuperior.columnWidths = new int[]{5, 90, 45, 45, 5, 0};
		gbl_painelSuperior.rowHeights = new int[]{5, 0, 0, 5, 0};
		gbl_painelSuperior.columnWeights = new double[]{0.0, 1.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		gbl_painelSuperior.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		painelSuperior.setLayout(gbl_painelSuperior);
		
		labelCaminhoDoArquivo = new JLabel("Caminho do Arquivo");
		labelCaminhoDoArquivo.setToolTipText("Caminho do arquivo que contém o autômato no diretório do computador");
		GridBagConstraints gbc_labelCaminhoDoArquivo = new GridBagConstraints();
		gbc_labelCaminhoDoArquivo.insets = new Insets(0, 0, 5, 5);
		gbc_labelCaminhoDoArquivo.gridx = 1;
		gbc_labelCaminhoDoArquivo.gridy = 1;
		painelSuperior.add(labelCaminhoDoArquivo, gbc_labelCaminhoDoArquivo);
		
		campoCaminhoDoArquivo = new JTextField();
		campoCaminhoDoArquivo.setFont(new Font("Dialog", Font.PLAIN, 16));
		
		//Tratador de acoes para o campo selecionar arquivo
		campoCaminhoDoArquivo.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) { //Carrega o arquivo em que esta carregado o automato ao apertar enter no campo do caminho do arquivo
				if(e.getKeyChar() == 10)
					carregarArquivo();
			}
			
			@Override
			public void keyReleased(KeyEvent e) { //Habilita ou desabilita o botao OK
				if(campoCaminhoDoArquivo.getText().isEmpty())
					botaoOk.setEnabled(false);
				else
					botaoOk.setEnabled(true);
			}
		});
		
		campoCaminhoDoArquivo.setBackground(Color.WHITE);
		GridBagConstraints gbc_campoCaminhoDoArquivo = new GridBagConstraints();
		gbc_campoCaminhoDoArquivo.insets = new Insets(0, 0, 5, 5);
		gbc_campoCaminhoDoArquivo.fill = GridBagConstraints.HORIZONTAL;
		gbc_campoCaminhoDoArquivo.gridx = 1;
		gbc_campoCaminhoDoArquivo.gridy = 2;
		painelSuperior.add(campoCaminhoDoArquivo, gbc_campoCaminhoDoArquivo);
		campoCaminhoDoArquivo.setColumns(10);
		
		botaoSelecionarArquivo = new JButton("Selecionar Arquivo");
		//Tratador de acoes para o botao selecionar arquivo
		botaoSelecionarArquivo.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) { //Abre a tela de selecao de arquivo
				selecionarArquivo();
			}
		});
		
		botaoSelecionarArquivo.setToolTipText("Selecionar o arquivo por meio de uma interface gráfica");
		GridBagConstraints gbc_botaoSelecionarArquivo = new GridBagConstraints();
		gbc_botaoSelecionarArquivo.insets = new Insets(0, 0, 5, 5);
		gbc_botaoSelecionarArquivo.gridx = 2;
		gbc_botaoSelecionarArquivo.gridy = 2;
		painelSuperior.add(botaoSelecionarArquivo, gbc_botaoSelecionarArquivo);
	
		botaoOk = new JButton("OK");
		//Tratador de acoes para o botao ok
		botaoOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) { //Carrega o arquivo que contem o automato para o programa
				carregarArquivo();
			}
		});
		
		botaoOk.setToolTipText("Carregar o arquivo para o programa");
		GridBagConstraints gbc_botaoOk = new GridBagConstraints();
		gbc_botaoOk.insets = new Insets(0, 0, 5, 5);
		gbc_botaoOk.gridx = 3;
		gbc_botaoOk.gridy = 2;
		painelSuperior.add(botaoOk, gbc_botaoOk);
		
		//Definicoes do painel central
		painelCentral = new JPanel();
		painelCentral.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		painelCentral.setBackground(Color.LIGHT_GRAY);
		GridBagConstraints gbc_painelCentral = new GridBagConstraints();
		gbc_painelCentral.insets = new Insets(0, 0, 5, 5);
		gbc_painelCentral.fill = GridBagConstraints.BOTH;
		gbc_painelCentral.gridx = 1;
		gbc_painelCentral.gridy = 2;
		janela.getContentPane().add(painelCentral, gbc_painelCentral);
		GridBagLayout gbl_painelCentral = new GridBagLayout();
		gbl_painelCentral.columnWidths = new int[]{5, 297, 0, 5, 0};
		gbl_painelCentral.rowHeights = new int[]{0, 0, 5, 0};
		gbl_painelCentral.columnWeights = new double[]{0.0, 1.0, 1.0, 0.0, Double.MIN_VALUE};
		gbl_painelCentral.rowWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
		painelCentral.setLayout(gbl_painelCentral);
		
		labelFita= new JLabel("Fita");
		labelFita.setToolTipText("Fita de entrada do autômato");
		GridBagConstraints gbc_labelFita = new GridBagConstraints();
		gbc_labelFita.insets = new Insets(0, 0, 5, 5);
		gbc_labelFita.gridx = 1;
		gbc_labelFita.gridy = 0;
		painelCentral.add(labelFita, gbc_labelFita);
		
		labelPilha = new JLabel("Pilha");
		labelPilha.setToolTipText("Pilha atual do autômato");
		GridBagConstraints gbc_labelPilha = new GridBagConstraints();
		gbc_labelPilha.insets = new Insets(0, 0, 5, 5);
		gbc_labelPilha.gridx = 2;
		gbc_labelPilha.gridy = 0;
		painelCentral.add(labelPilha, gbc_labelPilha);
		
		scrollFita = new JScrollPane();
		GridBagConstraints gbc_scrollFita = new GridBagConstraints();
		gbc_scrollFita.fill = GridBagConstraints.BOTH;
		gbc_scrollFita.insets = new Insets(0, 0, 5, 5);
		gbc_scrollFita.gridx = 1;
		gbc_scrollFita.gridy = 1;
		painelCentral.add(scrollFita, gbc_scrollFita);
		
		textoFita = new JTextArea();
		textoFita.setFont(new Font("Dialog", Font.PLAIN, 16));
		textoFita.setTabSize(4);
		textoFita.setEditable(false);
		scrollFita.setViewportView(textoFita);
		
		scrollPilha = new JScrollPane();
		GridBagConstraints gbc_scrollPilha = new GridBagConstraints();
		gbc_scrollPilha.insets = new Insets(0, 0, 5, 5);
		gbc_scrollPilha.fill = GridBagConstraints.BOTH;
		gbc_scrollPilha.gridx = 2;
		gbc_scrollPilha.gridy = 1;
		painelCentral.add(scrollPilha, gbc_scrollPilha);
		
		textoPilha = new JTextArea();
		textoPilha.setFont(new Font("Dialog", Font.PLAIN, 16));
		textoPilha.setEditable(false);
		scrollPilha.setViewportView(textoPilha);
		
		//Definicoes do painel inferior
		painelInferior = new JPanel();
		painelInferior.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		painelInferior.setBackground(Color.LIGHT_GRAY);
		GridBagConstraints gbc_painelInferior = new GridBagConstraints();
		gbc_painelInferior.insets = new Insets(0, 0, 5, 5);
		gbc_painelInferior.fill = GridBagConstraints.BOTH;
		gbc_painelInferior.gridx = 1;
		gbc_painelInferior.gridy = 3;
		janela.getContentPane().add(painelInferior, gbc_painelInferior);
		GridBagLayout gbl_painelInferior = new GridBagLayout();
		gbl_painelInferior.columnWidths = new int[]{5, 0, 5, 0};
		gbl_painelInferior.rowHeights = new int[]{5, 0, 0, 0, 5, 0};
		gbl_painelInferior.columnWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
		gbl_painelInferior.rowWeights = new double[]{0.0, 0.0, 0.0, 1.0, 0.0, Double.MIN_VALUE};
		painelInferior.setLayout(gbl_painelInferior);
		
		labelDigiteAPalavra = new JLabel("Digite a palavra a ser processada");
		GridBagConstraints gbc_labelDigiteAPalavra = new GridBagConstraints();
		gbc_labelDigiteAPalavra.insets = new Insets(0, 0, 5, 5);
		gbc_labelDigiteAPalavra.gridx = 1;
		gbc_labelDigiteAPalavra.gridy = 1;
		painelInferior.add(labelDigiteAPalavra, gbc_labelDigiteAPalavra);
		
		campoPalavraAProcessar = new JTextField();
		campoPalavraAProcessar.setFont(new Font("Dialog", Font.PLAIN, 16));
		
		//Tratador de acoes do campo palavra a processar
		campoPalavraAProcessar.addKeyListener(new KeyAdapter() {
			@Override
			public void keyReleased(KeyEvent e) { //Habilita ou nao o botao processar
				botaoProcessar.setEnabled(true);
			}
			
			@Override
			public void keyPressed(KeyEvent e) { //Processa a palavra contida no campo palavra a processar ao apertar enter no campo
				if(e.getKeyChar() == 10 && botaoProcessar.isEnabled()) {
					processarPalavra();
				}
			}
		});
		
		GridBagConstraints gbc_campoPalavraAProcessar = new GridBagConstraints();
		gbc_campoPalavraAProcessar.insets = new Insets(0, 0, 5, 5);
		gbc_campoPalavraAProcessar.fill = GridBagConstraints.HORIZONTAL;
		gbc_campoPalavraAProcessar.gridx = 1;
		gbc_campoPalavraAProcessar.gridy = 2;
		painelInferior.add(campoPalavraAProcessar, gbc_campoPalavraAProcessar);
		campoPalavraAProcessar.setColumns(10);
		
		painelBotoesInferiores = new JPanel();
		painelBotoesInferiores.setBackground(Color.LIGHT_GRAY);
		GridBagConstraints gbc_painelBotoesInferiores = new GridBagConstraints();
		gbc_painelBotoesInferiores.insets = new Insets(0, 0, 5, 5);
		gbc_painelBotoesInferiores.fill = GridBagConstraints.BOTH;
		gbc_painelBotoesInferiores.gridx = 1;
		gbc_painelBotoesInferiores.gridy = 3;
		painelInferior.add(painelBotoesInferiores, gbc_painelBotoesInferiores);
		GridBagLayout gbl_painelBotoesInferiores = new GridBagLayout();
		gbl_painelBotoesInferiores.columnWidths = new int[]{5, 0, 0, 5, 0};
		gbl_painelBotoesInferiores.rowHeights = new int[]{0, 0};
		gbl_painelBotoesInferiores.columnWeights = new double[]{0.0, 1.0, 1.0, 1.0, Double.MIN_VALUE};
		gbl_painelBotoesInferiores.rowWeights = new double[]{0.0, Double.MIN_VALUE};
		painelBotoesInferiores.setLayout(gbl_painelBotoesInferiores);
		
		botaoProcessar = new JButton("Processar");
		botaoProcessar.setToolTipText("Processar todas as letras da palavra");
		//Tratador de acoes do botao processar
		botaoProcessar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) { //Processa a palavra que esta no campo palavra a processar o clicar no botao processar
				processarPalavra();
			}
		});
		
		GridBagConstraints gbc_botaoProcessar = new GridBagConstraints();
		gbc_botaoProcessar.fill = GridBagConstraints.HORIZONTAL;
		gbc_botaoProcessar.insets = new Insets(0, 0, 0, 5);
		gbc_botaoProcessar.gridx = 1;
		gbc_botaoProcessar.gridy = 0;
		painelBotoesInferiores.add(botaoProcessar, gbc_botaoProcessar);
		
		botaoReiniciar = new JButton("Reiniciar");
		botaoReiniciar.setToolTipText("Reiniciar o programa completamente");
		//Tratador de acoes do botao reiniciar
		botaoReiniciar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) { //Reiniciar o programa
				reiniciar();
			}
		});
		
		botaoLimparProcessamento = new JButton("Limpar Processamento");
		botaoLimparProcessamento.setToolTipText("Limpar o processamento da palavra");
		//Tratador de acoes do botao limpar processamento
		botaoLimparProcessamento.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				limparProcessamento();
			}
		});
		
		GridBagConstraints gbc_botaoLimparProcessamento = new GridBagConstraints();
		gbc_botaoLimparProcessamento.fill = GridBagConstraints.HORIZONTAL;
		gbc_botaoLimparProcessamento.insets = new Insets(0, 0, 0, 5);
		gbc_botaoLimparProcessamento.gridx = 2;
		gbc_botaoLimparProcessamento.gridy = 0;
		painelBotoesInferiores.add(botaoLimparProcessamento, gbc_botaoLimparProcessamento);
		GridBagConstraints gbc_botaoReiniciar = new GridBagConstraints();
		gbc_botaoReiniciar.fill = GridBagConstraints.HORIZONTAL;
		gbc_botaoReiniciar.gridx = 3;
		gbc_botaoReiniciar.gridy = 0;
		painelBotoesInferiores.add(botaoReiniciar, gbc_botaoReiniciar);
		janela.setBackground(Color.LIGHT_GRAY);
		janela.setTitle("Autômato com Pilha Determinístico");
		janela.setBounds(100, 100, 700, 470);
		janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}
	
	/* Metodo que carrega o arquivo que contem o automato para o programa
	 * Entrada: 	 Nenhuma
	 * Retorno: 	 Nenhum
	 * Pre-condicao: Nenhuma
	 * Pos-condicao: O arquivo e carregado
	 */
	private void carregarArquivo() {
		arquivo = new Leitura();
		try {
			automato = new Automato(arquivo.LerArquivo(campoCaminhoDoArquivo.getText()));
			JTextArea textArea = new JTextArea(25,40);
			textArea.setText(automato.toString());
			textArea.setEditable(false);
			JScrollPane scrollpane = new JScrollPane(textArea);
			JOptionPane.showMessageDialog(janela, scrollpane,"Autômato carregado",JOptionPane.INFORMATION_MESSAGE);
		}catch (Exception e2) {
			JOptionPane.showMessageDialog(janela,"Arquivo inválido","Mensagem",JOptionPane.ERROR_MESSAGE);
		}
	}
	
	/* Metodo que seleciona o arquivo que contem o automato para ser carregado para o programa
	 * Entrada: 	 Nenhuma
	 * Retorno: 	 Nenhum
	 * Pre-condicao: Nenhuma
	 * Pos-condicao: O arquivo e selecionado
	 */
	private void selecionarArquivo() {
		JFileChooser j = new JFileChooser();
		String aux = null;
		j.showOpenDialog(null);
		try {
			aux = j.getSelectedFile().getAbsoluteFile().toString();		
			campoCaminhoDoArquivo.setText(aux);
			botaoOk.setEnabled(true);
			JOptionPane.showMessageDialog(janela, "Arquivo selecionado com sucesso !",
					"Mensagem",JOptionPane.INFORMATION_MESSAGE);
		}catch (Exception e2) {
			JOptionPane.showMessageDialog(janela, "Arquivo não selecionado !",
					"Mensagem",JOptionPane.ERROR_MESSAGE);
		}
	}
	
	/* Metodo que processa a palavra contida no campo processar palavra
	 * Entrada: 	 Nenhuma
	 * Retorno: 	 Nenhum
	 * Pre-condicao: Nenhuma
	 * Pos-condicao: A palavra e processada
	 */
	private void processarPalavra() {
		if(automato != null) {
			automato.getPilha().limparPilha();
			automato.processa(campoPalavraAProcessar.getText());
			textoFita.setText(automato.getTextoFita());
			textoPilha.setText(automato.getTextoPilha());
		}else {
			JOptionPane.showMessageDialog(null, "Nenhum autômato foi carregado","Mensagem",JOptionPane.ERROR_MESSAGE);
		}
	}
	
	/* Metodo que reinicia o programa
	 * Entrada: Nenhuma
	 * Retorno: Nenhum
	 * Pre-condicao: Nenhuma
	 * Pos-condica: Todas as informacoes do programa sao reiniciadas
	 */
	private void reiniciar() {
		Integer resetar;
		Locale local = new Locale("pt","BR");
		JOptionPane.setDefaultLocale(local);
		resetar = JOptionPane.showConfirmDialog(janela, "Resetar o programa ?",
				"Selecione uma opção",JOptionPane.YES_NO_OPTION);
		if(resetar == 0) {
			automato = null;
			campoCaminhoDoArquivo.setText("");
			campoPalavraAProcessar.setText("");
			textoPilha.setText("");
			textoFita.setText("");
			botaoProcessar.setEnabled(true);
			botaoOk.setEnabled(false);
			JOptionPane.showMessageDialog(janela, "Programa resetado com sucesso !");
		}
	}

	/* Metodo que limpa o processamento de uma palavra
	 * Entrada: Nenhuma
	 * Retorno: Nenhum
	 * Pre-condicao: Nenhuma
	 * Pos-condicao: Todo o processamento da palavra e apagado
	 */
	private void limparProcessamento() {
		Integer resetar;
		Locale local = new Locale("pt","BR");
		JOptionPane.setDefaultLocale(local);
		resetar = JOptionPane.showConfirmDialog(janela, "Limpar o processamento ?",
				"Selecione uma opção",JOptionPane.YES_NO_OPTION);
		if(resetar == 0) {
			textoFita.setText("");
			textoPilha.setText("");
			campoPalavraAProcessar.setText("");
			JOptionPane.showMessageDialog(janela, "Processamento limpo com sucesso !");
		}
	}

}
