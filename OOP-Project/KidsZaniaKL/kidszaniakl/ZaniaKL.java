package kidszaniakl;
import java.util.*;

public class ZaniaKL {

	public static void main(String[] args) {
		
		System.out.println("Welcome To KidZania School, KL");
		
		String parentName; String parentID; String studentName;
		int hours; double deposits;
		char opt; int choice; int exit;
		Scanner keyboard = new Scanner(System.in); 
		
		KidZania kid;
		System.out.println("Register");
		System.out.println("--------");
		
		System.out.print("Enter Student Name: ");
		studentName = keyboard.next();
		
		System.out.print("Enter your name: ");
		parentName = keyboard.next();
		
		System.out.print("Enter parent ID: ");
		parentID = keyboard.next();
		
		do {
			
			System.out.print("Enter deposits RM50: ");
			deposits = keyboard.nextDouble();
			
			if (deposits < 50)
				System.out.println("Deposit must be RM50");
		} while (deposits < 50);
		
		System.out.print("Enter duration(in hours): ");
		hours = keyboard.nextInt();
		
		kid = new KidZania(studentName, parentName, parentID, deposits);
		System.out.println("Successfully Registered");
		
		do {
			
		System.out.println(kid.toString());
		
		System.out.print("Press 1 to get if a card is lost");
		choice = keyboard.nextInt();
	    
		if (choice == 1)
		{
			System.out.print("1. Y/N for lost card: ");
			opt = keyboard.next().charAt(0);   
			
			if (opt == 'Y')
				kid.DepositDeduct();
		}
		
		System.out.println("You can press 0 to exit our system or 1 to see details:");
	    exit = keyboard.nextInt(); 
	    
	}while(exit >= 0); 
	    
  }
 }

