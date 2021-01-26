// Write a JDBC application displays the
// employee numbers who are having
// maximum and minimum salaries from the database.

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class EmployeeDB {
    JLabel jlab;
    static final String dbClass = "com.mysql.jdbc.Driver";

    EmployeeDB() {
        JButton jbtnMin = new JButton("Min Salary");
        JButton jbtnMax = new JButton("Max Salary");
        JFrame jfrm = new JFrame("Employee Details");
        jfrm.setLayout(new GridLayout(3,1));
        jfrm.setSize(300, 300);
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        jbtnMin.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                fetchDatabase(1);
            }
        });

        jbtnMax.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                fetchDatabase(2);
            }
        });

        jfrm.add(jbtnMin);
        jfrm.add(jbtnMax);
        jlab = new JLabel("Press a button.",JLabel.CENTER);
        jfrm.add(jlab);
        jfrm.setVisible(true);
    }
    void fetchDatabase(int code){
        java.sql.Connection conn = null;
        try {
            String URL = "jdbc:mysql://127.0.0.1:3306/company?allowPublicKeyRetrieval=true&useSSL=false";
            String DB_USERNAME = "root";
            String DB_PASSWORD = "Vishnu@1524";
            Class.forName(dbClass).newInstance();
            conn = java.sql.DriverManager.getConnection(URL, DB_USERNAME, DB_PASSWORD);
        }catch(ClassNotFoundException e){
            System.out.println("error in loading driver"+e);
            System.exit(1);
        }
        catch(Exception e){
            System.out.println("error in connection"+e);
            System.exit(0);
        }

        try{
            java.sql.Statement s = conn.createStatement();
            String query1 = "SELECT * FROM `EMPLOYEE` WHERE emp_sal IN (SELECT MIN(emp_sal) FROM EMPLOYEE)";
            String query2 = "SELECT * FROM `EMPLOYEE` WHERE emp_sal IN (SELECT MAX(emp_sal) FROM EMPLOYEE)";
            java.sql.ResultSet r;
            if(code == 1){
                r = s.executeQuery(query1);
            }else{
                r = s.executeQuery(query2);
            }
            if(r.next()){
                jlab.setText(r.getString("emp_id")+ " | " +
                r.getString("emp_name") + " | Rs " +
                r.getString("emp_sal") + "/-");
            }
        }
        catch(Exception e) {
            System.out.println(e);
            System.exit(0);
        }
    }
    public static void main(String args[]) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new EmployeeDB();
            }
        });
    }
}
