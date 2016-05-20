/**
 * Created by xcc on 2016/5/19.
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class testTable {
    public static void main(String[] argv)
    {
        //System.out.println("Hello World");
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                JFrame frame = new PlanetTableFrame();
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setVisible(true);
            }
        });
    }
}

class PlanetTableFrame extends JFrame
{
    public PlanetTableFrame()
    {
        setTitle("testTable");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        final JTable table = new JTable(cells, columnNames);
        table.setAutoCreateRowSorter(true);
        add(new JScrollPane(table), BorderLayout.CENTER);
        JButton printButton = new JButton("Print");
        printButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try
                {
                    table.print(); // It will connect to printer.
                }
                catch (java.awt.print.PrinterException ew)
                {
                    ew.printStackTrace();
                }
            }
        });

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(printButton);
        add(buttonPanel, BorderLayout.SOUTH);
    }

    private Object[][] cells = {{"2016-5-20", 100000, 0.9, false, Color.yellow}, {"2016-5-19", 100000, 0.8, false, Color.yellow}, {"2016-5-18", 100000, 0.7, false, Color.yellow}};

    private String[] columnNames = {"Date", "Used Capacity", "Ratio to VP Capacity"};

    private static final int DEFAULT_WIDTH = 400;
    private static final int DEFAULT_HEIGHT = 200;
}
