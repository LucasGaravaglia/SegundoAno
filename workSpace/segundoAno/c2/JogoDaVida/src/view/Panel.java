package view;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class Panel extends JPanel {
	private static final long serialVersionUID = 508369234136358064L;
	private int size;
	private int matriz[][];
	
	public Panel ( int size ) {
		this.size = size;
		this.matriz = new int[size+2][size+2];
	}
	
	public void setIteracao( int matriz[][] ) {
		this.matriz = matriz;
		repaint();
	}
 	
	@Override
	public void paint(Graphics g) {
		double h =  (double)getHeight()/(double)size;
		double w =  (double)getWidth()/(double)size;
		
		double y=0, x;
		for (int i=1; i<=size; i++) {
			x = 0;
			for (int j=1; j<=size; j++) {
				g.setColor( matriz[i][j]==1? Color.BLUE : Color.LIGHT_GRAY );
				g.fillRect( (int)x, (int)y, (int)w-1, (int)h-1);
				x += w;
			}
			y += h;
		}		
	}
	
}
