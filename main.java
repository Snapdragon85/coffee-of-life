import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class main extends JPanel {
    private final int rows = 20;
    private final int cols = 20;

    boolean[][] cells = new boolean[10][10];
    

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        int cellWidth = getWidth() / cols;
        int cellHeight = getHeight() / rows;

        // Draw horizontal lines
        for (int r = 0; r <= rows; r++) {
            g.drawLine(0, r * cellHeight, getWidth(), r * cellHeight);
        }

        // Draw vertical lines
        for (int c = 0; c <= cols; c++) {
            g.drawLine(c * cellWidth, 0, c * cellWidth, getHeight());
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Coffee's Game of Life");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);
        frame.add(new main());
        frame.setVisible(true);
    }
}
