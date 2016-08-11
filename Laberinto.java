/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author wadeowen
 */
public class Laberinto {
    
    private Lista lista;
    private boolean error;
    private boolean resuelto;
    private int[][] maze;
    private String direc = "";
    
            
    public Laberinto(int[][] ma){
        this.maze = ma;
        direc = "";
        lista = new Lista();
        lista.setRaiz(new Nodo(0));
    }
    
    
    public void solveMaze(Nodo t, int x, int y){
        if(t.getValue() == -3){
            System.out.println("Se resolvio el Laberinto.");
        }else{
            System.out.println(Integer.toString(x)+","+Integer.toString(y));
            t = addNodos(t,x,y);
            if(deadEnd(t)){
                if(direc.equals(""))
                    direc = firstDirec(t);
                else
                    direc = invDirec(direc);
            }else{
                direc = newDirec(t);
            }
            t.setValue(t.getValue()+1);
            if(direc.equals("right"))
                solveMaze(t.getRight(),x+1,y);
            else
                if(direc.equals("left"))
                    solveMaze(t.getLeft(),x-1,y);
                else
                    if(direc.equals("up"))
                        solveMaze(t.getUp(),x,y+1);
                    else
                        if(direc.equals("down"))
                            solveMaze(t.getDown(),x,y-1);
        }
    }
    
    public Nodo addNodos(Nodo t, int x, int y){
        int cont = 0;
        //System.out.println(maze[x][y-1]);
        if(maze[x][y+1] == 0 || maze[x][y+1] == -3){
            t = lista.addNodoUp(maze[x][y+1], t);
        }
        if(maze[x][y-1] == 0 || maze[x][y-1] == -3){
            t = lista.addNodoDown(maze[x][y-1], t);
        }
        if(maze[x+1][y] == 0 || maze[x+1][y] == -3){
            t = lista.addNodoRight(maze[x+1][y], t);
        }
        if(maze[x-1][y] == 0 || maze[x-1][y] == -3){
            t = lista.addNodoLeft(maze[x-1][y], t);
        }
        
        return t;
    }
   
    
    public boolean deadEnd(Nodo t){
        int cont = 0;
        
        if(t.getDown() == null)
            cont++;
        if(t.getUp() == null)
            cont++;
        if(t.getRight() == null)
            cont++;
        if(t.getLeft() == null)
            cont++;
        
        return cont == 3;
    }
    
    public String newDirec(Nodo t){
        int cont = 0;
        int riV = 1000;
        int leV = 1000;
        int doV = 1000;
        int upV = 1000;
        String newDir = "N";
        
        
        if(t.getDown() != null)
            doV = t.getDown().getValue();
        if(t.getUp() != null)
            upV = t.getUp().getValue();
        if(t.getRight() != null)
            riV = t.getRight().getValue();
        if(t.getLeft() != null)
            leV = t.getLeft().getValue();
        
        if(direc.equals("right")){
            if(doV<=upV && doV<=riV)
                return "down";
            if(riV<=upV)
                return "right";
            return "up";
        }
        
        if(direc.equals("left")){
            if(upV<=doV && upV<=leV)
                return "up";
            if(leV<=doV)
                return "left";
            return "down";
        }
        
        if(direc.equals("up")){
            if(riV<=upV && riV<=leV)
                return "right";
            if(upV<=leV)
                return "up";
            return "left";
        }
        
        if(direc.equals("down")){
            if(leV<=doV && leV<=riV)
                return "left";
            if(doV<=riV)
                return "down";
            return "right";
        }
        
        return newDir;
        
    }
    
    public String invDirec(String s){
        if(s.equals("right"))
            return "left";
        if(s.equals("left"))
            return "right";
        if(s.equals("up"))
            return "down";
        if(s.equals("down"))
            return "up";
        return s;
    }
    
    public String firstDirec(Nodo t){
        
        if(t.getUp() != null && (t.getUp().getValue()>=0 || t.getUp().getValue()==-3))
            return "up";
        
        if(t.getDown() != null && (t.getDown().getValue()>=0 || t.getDown().getValue()==-3))
            return "down";
        
        if(t.getRight() != null && (t.getRight().getValue()>=0 || t.getRight().getValue()==-3))
            return "right";
        
        if(t.getLeft() != null && (t.getLeft().getValue()>=0  || t.getLeft().getValue()==-3))
            return "left";
        
        return "";
    }
    
    public Lista getLista(){
        return this.lista;
    }
 
}
