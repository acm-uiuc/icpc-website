// Notice contestants that coordinates are given in (x, y) order.
import java.io.*;
import java.util.*;

public class Main {

    public static int[] move(int[] pos, int dir) {
        int moveH = 0, moveW = 0;
        switch (dir) {
            case 0:
                moveH = 1;
                break;
            case 1:
                moveW = 1;
                break;
            case 2:
                moveH = -1;
                break;
            case 3:
                moveW = -1;
                break;
        }
        return new int[]{pos[0] + moveH, pos[1] + moveW};
    }

    public static boolean off(int H, int W, int[] pos) {
        return (pos[0] < 0 || pos[0] >= H || pos[1] < 0 || pos[1] >= W);
    }

    public static void main(String[] args) {
        char[] map = new char[255];
        map['N'] = 0;
        map['E'] = 1;
        map['S'] = 2;
        map['W'] = 3;
        int[] invMap = new int[4];
        invMap[0] = 'N';
        invMap[1] = 'E';
        invMap[2] = 'S';
        invMap[3] = 'W';
        Scanner sc = new Scanner(System.in);
        int W = sc.nextInt() + 1;
        int H = sc.nextInt() + 1;
        boolean[][] grid = new boolean[H][W];
        while (sc.hasNext()) {
            int cw = sc.nextInt();
            int ch = sc.nextInt();
            int[] pos = new int[]{ch, cw};
            int dir = map[sc.next().charAt(0)];
            String moves = sc.next();
            boolean offGround = false;
            for (int i = 0; i < moves.length(); i++) {
                if (offGround) break;
                char mv = moves.charAt(i);
                switch (mv) {
                    case 'L':
                        dir = (dir + 3) % 4;
                        break;
                    case 'R':
                        dir = (dir + 1) % 4;
                        break;
                    case 'F':
                        int[] nextPos = move(pos, dir);
                        if (off(H, W, nextPos)) {
                            if (!grid[pos[0]][pos[1]]) {
                                grid[pos[0]][pos[1]] = true;
                                offGround = true;
                            }
                            continue;
                        }
                        pos = nextPos;
			break;
                }
            }
            System.out.print(pos[1] + " " + pos[0] + " " + (char)invMap[dir]);
            if (offGround) {
                System.out.println(" LOST");
            } else {
                System.out.println();
            }
        }
    }
}
