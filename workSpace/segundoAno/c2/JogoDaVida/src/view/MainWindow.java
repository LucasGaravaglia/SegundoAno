package view;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.BevelBorder;

import thread.Observador;
import thread.SimulaVida;

public class MainWindow implements Observador {
	private final int size=300;
	
	private JFrame frame;
	private Panel panel;
	private SimulaVida life=null;
	private JButton btnIniciar;
	private JButton btnSuspender;
	private JButton btnRetomar;
	private JButton btnParar;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainWindow window = new MainWindow();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MainWindow() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		
		//frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		panel = new Panel(size);
		frame.getContentPane().add(panel, BorderLayout.CENTER);
		
		JPanel pbuttons = new JPanel();
		pbuttons.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		frame.getContentPane().add(pbuttons, BorderLayout.SOUTH);
		pbuttons.setLayout(new BorderLayout(0, 0));
		
		JButton btnFechar = new JButton("Fechar");
		btnFechar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (life!=null) life.finalize();
				System.exit(0);
			}
		});
		pbuttons.add(btnFechar, BorderLayout.EAST);
		
		JPanel panel_1 = new JPanel();
		FlowLayout flowLayout = (FlowLayout) panel_1.getLayout();
		flowLayout.setVgap(0);
		flowLayout.setHgap(0);
		pbuttons.add(panel_1, BorderLayout.WEST);
		
		btnIniciar = new JButton("Iniciar");
		btnIniciar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				criarNovaThread();
			}

			
		});
		panel_1.add(btnIniciar);
		
		btnSuspender = new JButton("Suspender");
		btnSuspender.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				life.setPausado(true);
				btnIniciar.setEnabled(false);
				btnSuspender.setEnabled(false);
				btnRetomar.setEnabled(true);
				btnParar.setEnabled(true);
			}
		});
		panel_1.add(btnSuspender);
		
		btnParar = new JButton("Parar");
		btnParar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				life.finalize();
				life = null;
				btnIniciar.setEnabled(true);
				btnSuspender.setEnabled(false);
				btnRetomar.setEnabled(false);
				btnParar.setEnabled(false);
			}
		});
		
		btnRetomar = new JButton("Retomar");
		btnRetomar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				life.setPausado(false);
				btnIniciar.setEnabled(false);
				btnSuspender.setEnabled(true);
				btnRetomar.setEnabled(false);
				btnParar.setEnabled(true);
			}
		});
		panel_1.add(btnRetomar);
		panel_1.add(btnParar);
		
		frame.setBounds(100, 100, 450, 451+pbuttons.getHeight());
		btnIniciar.setEnabled(true);
		btnSuspender.setEnabled(false);
		btnRetomar.setEnabled(false);
		btnParar.setEnabled(false);
	}

	private void criarNovaThread() {
		this.life = new SimulaVida(this, size);
		this.life.start();
		btnIniciar.setEnabled(false);
		btnSuspender.setEnabled(true);
		btnRetomar.setEnabled(false);
		btnParar.setEnabled(true);
	}
	
	@Override
	public synchronized void mostrarTabuleiro(int[][] m) {
		panel.setIteracao ( m );	
	}

}
