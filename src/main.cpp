#include "raylib.h"
#include <map>
#include <string>
#include <iostream>
#include <vector>


using namespace std;


class Pieces{
    public:
        vector<string> PosP;
        Texture2D T;
        map<string,Vector2> pgn;
        

        Pieces(vector<string> PosP, Texture2D T, map<string,Vector2> pgn){
            this->PosP = PosP;
            this->T = T;
            this->pgn = pgn;
        }

        void DrawP(){
            for(auto& cord : PosP){
                DrawTexture(T, pgn[cord].x,pgn[cord].y,WHITE);
            }
        }
        


        
};


int main(){
    

    
    map<string, Vector2> pgn;


    int telaX = 800;
    int telaY = 800;
    int board = 8;
    int quadrado = telaX / board;


    InitWindow(telaX, telaY, "chess");
    SetTargetFPS(60);

    for(char coluna = 'A'; coluna <= 'H'; coluna++){
        for(int linha = 1;linha <= 8; linha++){
            string key = string(1,coluna) + to_string(linha);

            int colIndex = coluna -  'A';

            int rowIndex = 8 - linha; 

            float x = colIndex * quadrado;
            float y = rowIndex * quadrado;

            pgn[key] = Vector2{ x, y };
            
        }
    }

    for(auto& p : pgn){
        printf("%s -> (%.1f, %.1f)\n", p.first.c_str(), p.second.x, p.second.y);
    }

    
    Image p = LoadImage("../imgs/pieces/white/pawn.png");
    Image Q = LoadImage("../imgs/pieces/white/queen.png");
    Image K = LoadImage("../imgs/pieces/white/king.png");
    Image H = LoadImage("../imgs/pieces/white/knight.png");
    Image B = LoadImage("../imgs/pieces/white/bishop.png");
    Image T = LoadImage("../imgs/pieces/white/rook.png");

    int TamanhoIMG = 100;

    ImageResize(&T, TamanhoIMG, TamanhoIMG);
    ImageResize(&B, TamanhoIMG, TamanhoIMG);
    ImageResize(&H, TamanhoIMG, TamanhoIMG);
    ImageResize(&K, TamanhoIMG, TamanhoIMG);
    ImageResize(&p,TamanhoIMG,TamanhoIMG);
    ImageResize(&Q, TamanhoIMG,TamanhoIMG);

    Texture2D Tp = LoadTextureFromImage(p);
    Texture2D TQ = LoadTextureFromImage(Q);
    Texture2D TK = LoadTextureFromImage(K);
    Texture2D TH = LoadTextureFromImage(H);
    Texture2D TB = LoadTextureFromImage(B);
    Texture2D TT = LoadTextureFromImage(T);

    Pieces Pawn({"A2","B2","C2","D2","E2","F2","G2","H2"}, Tp,pgn);
    Pieces Queen({"D1"},TQ,pgn);
    Pieces King({"E1"},TK,pgn);
    Pieces vacalo({"B1","G1"},TH,pgn);
    Pieces papa({"C1","F1"},TB,pgn);
    Pieces TorresGemeas({"A1","H1"},TT, pgn);

    //
    Image pBlack = LoadImage("../imgs/pieces/black/pawn.png");
    Image QBlack = LoadImage("../imgs/pieces/black/queen.png");
    Image KBlack = LoadImage("../imgs/pieces/black/king.png");
    Image HBlack = LoadImage("../imgs/pieces/black/knight.png");
    Image BBlack = LoadImage("../imgs/pieces/black/bishop.png");
    Image TBlack = LoadImage("../imgs/pieces/black/rook.png");

    ImageResize(&TBlack, TamanhoIMG, TamanhoIMG);
    ImageResize(&BBlack, TamanhoIMG, TamanhoIMG);
    ImageResize(&HBlack, TamanhoIMG, TamanhoIMG);
    ImageResize(&KBlack, TamanhoIMG, TamanhoIMG);
    ImageResize(&pBlack,TamanhoIMG,TamanhoIMG);
    ImageResize(&QBlack, TamanhoIMG,TamanhoIMG);

    Texture2D TpBlack = LoadTextureFromImage(pBlack);
    Texture2D TQBlack = LoadTextureFromImage(QBlack);
    Texture2D TKBlack = LoadTextureFromImage(KBlack);
    Texture2D THBlack = LoadTextureFromImage(HBlack);
    Texture2D TBBlack = LoadTextureFromImage(BBlack);
    Texture2D TTBlack = LoadTextureFromImage(TBlack);

    Pieces PawnBlack({"A7","B7","C7","D7","E7","F7","G7","H7"}, TpBlack, pgn);
    Pieces QueenBlack({"D8"}, TQBlack, pgn);
    Pieces KingBlack({"E8"}, TKBlack, pgn);
    Pieces vacaloBlack({"B8","G8"}, THBlack, pgn);
    Pieces papaBlack({"C8","F8"}, TBBlack, pgn);
    Pieces TorresGemeasBlack({"A8","H8"}, TTBlack, pgn);



    while(!WindowShouldClose()){//MAIN LOOP!!!!
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for(int linha = 0; linha < board;linha++){
            for(int coluna = 0; coluna < board;coluna++){
                Color color = ((linha + coluna) % 2 == 0) ? WHITE : GRAY;
                DrawRectangle(coluna * quadrado, linha * quadrado, quadrado, quadrado, color);
                
            }

            
        }



        Pawn.DrawP();
        Queen.DrawP();
        King.DrawP();
        vacalo.DrawP();
        papa.DrawP();
        TorresGemeas.DrawP();
        //
        PawnBlack.DrawP();
        QueenBlack.DrawP();
        KingBlack.DrawP();
        vacaloBlack.DrawP();
        papaBlack.DrawP();
        TorresGemeasBlack.DrawP();

        EndDrawing();
    }
    UnloadTexture(Tp);


    return 0;
}

//g++ main.cpp -o main.exe -I"D:/raylib/src" -L"D:/raylib/build/raylib" -lraylib -lopengl32 -lgdi32 -lwinmm