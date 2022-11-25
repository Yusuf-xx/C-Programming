package kidszaniakl;

public abstract class Kids {
	
	  protected String StudentName;
	  protected String ParentName;
	  protected String ParentID;

	protected Kids(String StudentName, String ParentName, String ParentID) 
	{
	  this.StudentName = StudentName;
	  this.ParentName = ParentName;
	  this.ParentID = ParentID;
	}
	
	@Override 
	public abstract String toString();
	
	public abstract double DepositDeduct();
}

