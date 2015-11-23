package sphere;

import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

public class sController implements MouseMotionListener{
	
	private Sphere sphere;
	public sController(Sphere sphere){this.sphere=sphere;}
	@Override
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
		//sphere.setRadius(e.getX());	
		if(e.getX()<0)
			sphere.setRadius(0);
		else sphere.setRadius(e.getX());
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

}
