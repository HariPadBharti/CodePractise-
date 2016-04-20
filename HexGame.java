

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Polygon;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Stack;

import javax.swing.JComponent;
import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;

/**
 * 
 * @author Hpb, 
 *
 */
class HexGame {
    public static void main(String[] args) {

        Runnable r = new Runnable() {
            public void run() {
            int len=400;
            float area=(len*len)/2.0f;
            float l=(float)Math.sqrt(area);
            float p=0.866f*l;
            p=l/11;
            
            System.out.println("Area: "+area+" length: "+l+" P is :"+p);
            float shiftx=0,shifty=0;
            Info centralpts[][]=new Info[11][11];

                for(int jj=1;jj<=11;jj++){
                	
        for (int ii=1; ii<=11; ii++) {
                   // lineComponent.addHexagon((int)(shiftx+((p*ii)*1.45f)),(int)(shifty+(len/2)+((p*ii)/2)),(int)l/11);
                    centralpts[jj-1][ii-1]=new Info((int)(shiftx+((p*ii)*1.45f)),(int)(shifty+(len/2)+((p*ii)/2)),(int)l/11);
                   System.out.println("jj and ii is: "+jj+" "+ii+" Data is: "+centralpts[jj-1][ii-1].x+ " "+centralpts[jj-1][ii-1].y);
        }
        shiftx+=(1.51*p);
        shifty-=(p/2);
        }
                
LineComponent lineComponent = new LineComponent(len*2+50,len+50,centralpts);
                JOptionPane.showMessageDialog(null, lineComponent);
            }
        };
        SwingUtilities.invokeLater(r);
    }
}

class Info{
public int x;
public int y;
public char color;

public boolean wis=false;
public boolean wvis=false;

public int size;

public Info(int x,int y,int size){
    this.x=x;
    this.y=y;
    this.size=size;
    this.color='w';
    
}
}

class LineComponent extends JComponent  implements MouseListener{

/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
Info centralpts[][];
char color='r';

    LineComponent(int width, int height,Info centralpts[][]) {
        super();
        setPreferredSize(new Dimension(width,height));
       this.centralpts=centralpts;
       addMouseListener(this);
    }
    
   

    public void paintComponent(Graphics g) {
        g.setColor(Color.black);
        g.fillRect(0, 0, getWidth(), getHeight());
        g.setColor(Color.white);

int x1[]=new int[6];
int y1[]=new int[6];
int n=6;


        for(int i=0;i<11;i++){
            for(int j=0;j<11;j++){
            int l=centralpts[i][j].size;
            int x=centralpts[i][j].x;
            int y=centralpts[i][j].y;
            
            char c=centralpts[i][j].color;
            
            if(c=='w')
            g.setColor(Color.white);
            else if(c=='r')
            g.setColor(Color.red);
            else if(c=='b')
            g.setColor(Color.blue);
            
                int d=l/2;
                x1[0]=x-d;
                x1[1]=x+d;
                x1[2]=x+l;
                x1[3]=x+d;
                x1[4]=x-d;
                x1[5]=x-l;

                y1[0]=y-d;
                y1[1]=y-d;
                y1[2]=y;
                y1[3]=y+d;
                y1[4]=y+d;
                y1[5]=y;

                 Polygon p = new Polygon(x1, y1, n);

        g.fillPolygon(p);
        
                g.setColor(Color.black);
                
                g.drawLine(x-d,y-d,(x+d),(y-d));
                g.drawLine(x+d,y-d,x+l,y);
                g.drawLine(x+l,y,x+d,y+d);
                g.drawLine(x+d,y+d,x-d,y+d);
                g.drawLine(x-d,y+d,x-l,y);
                g.drawLine(x-l,y,x-d,y-d);
            }
        }
    }

	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		//System.out.println("Hello World");
		
	}

	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
		
	}

	@Override
	public void mousePressed(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	int [] getindex(int x,int y){
		int index[]=new int[2];
		
		int temp=centralpts[0][0].x-centralpts[0][1].x;
		float l=temp/1.5f;
		int i=0,j=0;
		for(i=0;i<11;i++){
			if(x<=(centralpts[0][i].x+l))
				break;
		}
		i--;
		
		if(i==-1){
			index[0]=-1;
			index[1]=-1;
			return index;
		}
		
		for(j=0;j<11;j++){
			if(y>=(centralpts[j][i-j].y+(l/2)))
				break;
		}
		i=i-j;
//For other half region
		if(x>(centralpts[10][0].x+l)){
			
			for(i=0;i<11;i++){
				if(x<=(centralpts[10][i].x+l))
					break;
			}
			i--;
			if(i==-1) {
				index[0]=-1;
				index[1]=-1;
				return index;
			}
		//	System.out.println(" X is "+i);
			
			for(j=10;j>=0;j--){
				//System.out.println("J is "+y+ " and "+(centralpts[j][10-j].y)+" and "+(10-j));
				if(y<=(centralpts[j][i+(10-j)].y-(l/2)))
					break;
			}
				i+=(10-j);			
		}
		
		
			index[0]=i;
			index[1]=j;
			return index;
		
	
	}
	
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		//System.out.println("Hello World "+e.getX()+" Y: "+e.getY());
		int x=e.getX();	int y=e.getY();
		
		
		//System.out.println(" J is :"+j);
		//System.out.println(" I is : "+i);
		int index[]=getindex(x,y);
		int j=index[1];
		int i=index[0];
		if(i==-1 || j==-1)return;
		
		if(centralpts[j][i].color=='w'){
			if(color=='r')color='b';
			else
				color='r';
			centralpts[j][i].color=color;
		}

		rundfs(color);
		repaint();
		
	}
	
	public void winner(char team){
		for(int j=0;j<11;j++){
			for(int i=0;i<11;i++){
				centralpts[j][i].color=team;
			}
		}
		repaint();
	}
	public void setToZero(){
		for(int i=0;i<11;i++){
			for(int j=0;j<11;j++){
				centralpts[i][j].wis=false;
				centralpts[i][j].wvis=false;
			}
		}
	}
	
	public void rundfs(char color){
		System.out.println("Color is"+color);
		if(color=='r'){
			//Check if Red wins
			boolean grid1=false,grid2=false;
			for(int j=0;j<11;j++ ){
				if(centralpts[j][0].color=='r' && !grid1)
					grid1=true;
				if(centralpts[j][10].color=='r' && !grid2)
					grid2=true;
			}
			//System.out.println("Grid is "+grid1+" "+grid2);
				if(!grid1 || !grid2)return;
				Info temp;
				
				int i=0,j=0;
				boolean winning=false;
				
				Stack<Info> st=new Stack<Info>();
				for(int k=0;k<11;k++){
					if(centralpts[k][0].color=='r'){
						st.push(centralpts[k][0]);
						temp=centralpts[k][0];
						temp.wis=true;
						
						while(!st.isEmpty()){
							int index[]=getindex(temp.x,temp.y);
							i=index[0];
							j=index[1];
							System.out.println("I is "+i +" J is "+j);
							
							if(i>9)winning=true;
							//Move Forward
							if((i+1)<11 && centralpts[j][i+1].color=='r' && !centralpts[j][i+1].wis && !centralpts[j][i+1].wvis)
							{
								temp=centralpts[j][i+1];
								st.push(temp);
								temp.wis=true;
								continue;
							}
							//Move diagonally, forward
							if((j-1)>=0  && (i+1)<11 && centralpts[j-1][i+1].color=='r' && !centralpts[j-1][i+1].wis && !centralpts[j-1][i+1].wvis){
								temp=centralpts[j-1][i+1];
								st.push(temp);
								temp.wis=true;
								continue;
							}
							//Move Sidewise(Right)
							if((j+1)<11 && centralpts[j+1][i].color=='r' && !centralpts[j+1][i].wis && !centralpts[j+1][i].wvis){
								temp=centralpts[j+1][i];
								st.push(temp);
								temp.wis=true;
								continue;
							}
							//Move Sidewise(left)
							if((j-1)>=0 && centralpts[j-1][i].color=='r' && !centralpts[j-1][i].wis && !centralpts[j-1][i].wvis){
								temp=centralpts[j-1][i];
								st.push(temp);
								temp.wis=true;
								continue;
							}
							
							//No Nodes found to go further
							temp.wvis=true;
							temp=st.pop();
							
													
						}						
					}
					if(winning){
						winner('r');
						return;
					}
				}
				
				
			setToZero();
			
		}
		else if(color=='b'){
			//Check if Blue wins
			
			boolean grid1=false,grid2=false;
			for(int j=0;j<11;j++ ){
				if(centralpts[0][j].color=='b' && !grid1)
					grid1=true;
				if(centralpts[10][j].color=='b' && !grid2)
					grid2=true;
			}
			//System.out.println("Grid is "+grid1+" "+grid2);
				if(!grid1 || !grid2)return;
				Info temp;
				
				int i=0,j=0;
				boolean winning=false;
				
				Stack<Info> st=new Stack<Info>();
				for(int k=0;k<11;k++){
					if(centralpts[0][k].color=='b'){
						st.push(centralpts[0][k]);
						temp=centralpts[0][k];
						temp.wis=true;
						
						while(!st.isEmpty()){
							int index[]=getindex(temp.x,temp.y);
							i=index[0];
							j=index[1];
							System.out.println("I is "+i +" J is "+j);
							
							if(j>9)winning=true;
							//Move Right(sidewise)
							if((i+1)<11 && centralpts[j][i+1].color=='b' && !centralpts[j][i+1].wis && !centralpts[j][i+1].wvis)
							{
								temp=centralpts[j][i+1];
								st.push(temp);
								temp.wis=true;
								continue;
							}
							//(Move Diagonally, forward)
							if((i-1)>=0  && (j+1)<11 && centralpts[j+1][i-1].color=='b' && !centralpts[j+1][i-1].wis && !centralpts[j+1][i-1].wvis){
								temp=centralpts[j+1][i-1];
								st.push(temp);
								temp.wis=true;
								continue;
							}
							
							//Move Forward
							if((j+1)<11 && centralpts[j+1][i].color=='b' && !centralpts[j+1][i].wis && !centralpts[j+1][i].wvis){
								temp=centralpts[j+1][i];
								st.push(temp);
								temp.wis=true;
								continue;
							}
							//Move Left(sidewise)
							if((i-1)>=0 && centralpts[j][i-1].color=='b' && !centralpts[j][i-1].wis && !centralpts[j][i-1].wvis){
								temp=centralpts[j][i-1];
								st.push(temp);
								temp.wis=true;
								continue;
							}
							
							//No Nodes found to go further
							temp.wvis=true;
							temp=st.pop();
							
													
						}						
					}
					if(winning){
						winner('b');
						return;
					}
				}
				
				
			setToZero();
			
			
			
			
		}
	}
}
