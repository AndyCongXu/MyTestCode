    import java.awt.*;  
    import java.awt.event.*;  
    import javax.swing.*;  
      
    public class JScrollBarExample implements AdjustmentListener {  
        JScrollBar scrollBar1;  
        JScrollBar scrollBar2;  
        JPanel panel1;  
        JLabel label2 = new JLabel("�̶ȣ�", JLabel.CENTER);  
      
        public JScrollBarExample() {  
            JFrame f = new JFrame("JScrollBarDemo");  
            Container contentPane = f.getContentPane();  
      
            JLabel label1 = new JLabel(new ImageIcon(".\\icons\\flower.jpg"));  
            panel1 = new JPanel();  
            panel1.add(label1);  
            /* 
             * ����һ����ֱ�����ᣬĬ�Ϲ�����λ����10�̶ȵĵط���extentֵ��10��minimumֵΪ0�� maximanֵΪ100����˹�����һ��ʼ�ڿ̶�10��λ���ϣ��ɹ����������СΪ100-10-0=90�̶ȣ�������Χ��0��90�С� 
             */  
            scrollBar1 = new JScrollBar(JScrollBar.VERTICAL, 10, 10, 0, 100);  
            scrollBar1.setUnitIncrement(1);// ������ҷ������ʱ��������̶�һ�εı仯����  
            scrollBar1.setBlockIncrement(10);// ���õ�����ڹ��������ϰ�һ���ǣ�������һ�������������С  
            scrollBar1.addAdjustmentListener(this);  
      
            scrollBar2 = new JScrollBar();// ����һ���յ�JScrollBar  
            scrollBar2.setOrientation(JScrollBar.HORIZONTAL);// ���ù����᷽��Ϊˮƽ����  
            scrollBar2.setValue(0);// ����Ĭ�Ϲ�����λ����0�̶ȵĵط���  
            scrollBar2.setVisibleAmount(20);// extentֵ��Ϊ20  
            scrollBar2.setMinimum(10);// minmumֵ��Ϊ10  
            scrollBar2.setMaximum(60);// maximanֵ��Ϊ60,��Ϊminmumֵ��Ϊ10���ɹ����������СΪ60-20-10=30  
            // ���̶ȣ�������Χ��10~40�С�  
            scrollBar2.setBlockIncrement(5);// ������ڹ��������ϰ�һ��ʱ��������һ�������������СΪ5���̶�  
            scrollBar2.addAdjustmentListener(this);  
      
            contentPane.add(panel1, BorderLayout.CENTER);  
            contentPane.add(scrollBar1, BorderLayout.EAST);  
            contentPane.add(scrollBar2, BorderLayout.SOUTH);  
            contentPane.add(label2, BorderLayout.NORTH);  
      
            f.setSize(new Dimension(200, 200));  
            f.setVisible(true);  
            f.addWindowListener(new WindowAdapter() {  
                public void windowClosing(WindowEvent e) {  
                    System.exit(0);  
                }  
            });  
        }  
      
        // ʵ��adjustmentValueChanged���������û��ı�ת��λ��ʱ���ὫĿǰ�Ĺ�����̶�д��labe2�ϡ�  
        public void adjustmentValueChanged(AdjustmentEvent e) {  
            if ((JScrollBar) e.getSource() == scrollBar1)  
                label2.setText("��ֱ�̶�" + e.getValue());// e.getValue()���õ�ֵ��scrollBar1.getValue()���õ�ֵһ����  
            if ((JScrollBar) e.getSource() == scrollBar2)  
                label2.setText("ˮƽ�̶�" + e.getValue());  
        }  
      
        public static void main(String[] args) {  
            new JScrollBarExample();  
        }  
      
    }  