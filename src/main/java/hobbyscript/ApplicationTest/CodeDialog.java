package hobbyscript.ApplicationTest;

import javax.swing.*;
import java.io.*;

/**
 * Created by liufengkai on 16/7/11.
 */
public class CodeDialog extends Reader {
    private String buffer = null;

    private int pos = 0;


    @Override
    public int read(char[] cbuf, int off, int len) throws IOException {
        if (buffer == null) {
            String in = showDialog();

            if (in == null) {
                return -1;
            } else {
                System.out.println(in);
                buffer = in + "\n";
                pos = 0;
            }
        }

        int size = 0;
        int length = buffer.length();

        while (pos < length && size < length) {
            cbuf[off + size++] = buffer.charAt(pos++);
        }

        if (pos == length) {
            buffer = null;
        }

        return size;
    }


    private String showDialog() {
        JTextArea area = new JTextArea(20, 40);
        JScrollPane pane = new JScrollPane(area);

        int result = JOptionPane.showOptionDialog(null, pane, "Input",
                JOptionPane.OK_CANCEL_OPTION,
                JOptionPane.PLAIN_MESSAGE,
                null, null, null);

        if (result == JOptionPane.OK_OPTION) {
            return area.getText();
        } else {
            return null;
        }
    }

    @Override
    public void close() throws IOException {

    }

    public static Reader file() throws FileNotFoundException {
        JFileChooser chooser = new JFileChooser();

        if (chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
            return new BufferedReader(new FileReader(chooser.getSelectedFile()));
        } else {
            throw new FileNotFoundException("no file specified ");
        }
    }
}
