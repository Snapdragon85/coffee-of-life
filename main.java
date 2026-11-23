import javax.swing.*;

public class main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Coffee's Game of Life");


            JPanel panel = new JPanel();
            panel.add(new JLabel("Hello world!"));
            panel.add(new JButton("Click Me"));
            

            frame.setSize(1000, 700);

            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            frame.setLocationRelativeTo(null);

            frame.add(panel);
            frame.setVisible(true);
        });
    }
}