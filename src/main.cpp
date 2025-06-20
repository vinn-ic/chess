#include "raylib.h"
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>



using namespace std;


class Pieces{
    public:
        vector<string> PosP;
        Texture2D T;
        map<string,Vector2> pgn;
        map<string, char> pgnForPieces;
        string piece;

        Pieces(vector<string> PosP, Texture2D T, map<string,Vector2> pgn, map<string, char> pgnForPieces,char piece){
            this->PosP = PosP;
            this->T = T;
            this->pgn = pgn;
            this->pgnForPieces = pgnForPieces;
            this->piece = piece;
        }
        void DrawP(){
            
            for(auto& cord : PosP){
                DrawTexture(T, pgn[cord].x,pgn[cord].y,WHITE);
            }
        }
        

        
        
};

Color YELLOW_LIGHT = {255, 255, 153, 255};


int main(){
    
    string casa;
    vector<string> casasAlvos;

    char pieceForCase;
    map<string, Vector2> pgn;
    map<string, char> pgnForPieces;


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
            if(key[1] == '2' || key[1] == '7'){
                pgnForPieces[key] = 'P';
            }else if(key == "A1" || key == "A8" || key == "H1" || key == "H8"){
                pgnForPieces[key] = 'T';
            }else if(key == "B1" || key == "B8" || key == "G1" || key == "G8"){
                pgnForPieces[key] = 'C';
            }else if(key == "C1" || key == "C8" || key == "F1" || key == "F8"){
                pgnForPieces[key] = 'B';
            }else if(key == "D1" || key == "D8"){
                pgnForPieces[key] = 'D';
            }else if(key == "E1" || key == "E8"){
                pgnForPieces[key] = 'R';
            }else{
                pgnForPieces[key] = '_';
            }
            
        }
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

    Pieces Pawn({"A2","B2","C2","D2","E2","F2","G2","H2"}, Tp,pgn, pgnForPieces,'P');
    Pieces Queen({"D1"},TQ,pgn, pgnForPieces,'D');
    Pieces King({"E1"},TK,pgn, pgnForPieces,'R');
    Pieces vacalo({"B1","G1"},TH,pgn,pgnForPieces,'C');
    Pieces papa({"C1","F1"},TB,pgn,pgnForPieces,'B');
    Pieces TorresGemeas({"A1","H1"},TT, pgn,pgnForPieces,'T');

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

    Pieces PawnBlack({"A7","B7","C7","D7","E7","F7","G7","H7"}, TpBlack, pgn,pgnForPieces,'P');
    Pieces QueenBlack({"D8"}, TQBlack, pgn,pgnForPieces,'D');
    Pieces KingBlack({"E8"}, TKBlack, pgn,pgnForPieces,'R');
    Pieces vacaloBlack({"B8","G8"}, THBlack, pgn,pgnForPieces,'C');
    Pieces papaBlack({"C8","F8"}, TBBlack, pgn,pgnForPieces,'B');
    Pieces TorresGemeasBlack({"A8","H8"}, TTBlack, pgn,pgnForPieces,'T');

    for(auto& p : pgn){
        printf("%s -> (%.1f, %.1f)\n", p.first.c_str(), p.second.x, p.second.y);
    }
 
    for(auto& PFP : pgnForPieces){
        printf("%s>>%c\n", PFP.first.c_str(), PFP.second);
    }

    while(!WindowShouldClose()){//MAIN LOOP!!!!
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for(int linha = 0; linha < board;linha++){
            for(int coluna = 0; coluna < board;coluna++){
                Color color = ((linha + coluna) % 2 == 0) ? WHITE : GRAY;
                DrawRectangle(coluna * quadrado, linha * quadrado, quadrado, quadrado, color);
               
            }  
        }
        if(!casa.empty()){
            DrawRectangle(pgn[casa].x,pgn[casa].y,100,100,YELLOW);
            
            switch(pieceForCase){
                case 'P':
                    if(casa[1] == '2'){

                        auto it = pgn.find(casa);
                        if (it != pgn.end()){
                            it++;
                            if(casasAlvos.size() >= 6){
                                casasAlvos.clear();
                            }else if(casasAlvos.size() <= 2){
                                casasAlvos.push_back(it->first.c_str());
                                
                            }
                            
                            if(it != pgn.end()){
                                DrawRectangle(it->second.x, it->second.y,100,100,YELLOW_LIGHT);
                                it++;
                                if(casasAlvos.size() <= 6){
                                    casasAlvos.push_back(it->first.c_str());
                                }
                                if(it != pgn.end()){
                                    DrawRectangle(it->second.x,it->second.y,100,100,YELLOW_LIGHT);
                                }
                            }
                        }       
                    }
                    else if(casa[1] == '7'){
                        auto it = pgn.find(casa);
                        if (it != pgn.end()){
                            it--;
                            
                            if(it != pgn.end()){
                                DrawRectangle(it->second.x, it->second.y,100,100,YELLOW_LIGHT);
                                it--;
                                if(it != pgn.end()){
                                    DrawRectangle(it->second.x,it->second.y,100,100,YELLOW_LIGHT);
                                }
                            }
                        } 
                    }
                    break;
            
            }
        }   

        Vector2 posMouse = GetMousePosition();


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
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            float x = posMouse.x;
            float y = posMouse.y;

            for(auto& cord : pgn){
                float cx = cord.second.x;
                float cy = cord.second.y;
                
                if(abs((cx+50) - x) <= 50 && abs((cy + 50) - y) <= 50){
                    casa = cord.first.c_str();
                    pieceForCase = pgnForPieces[casa];
                }

            }
            
            
            printf("click >> %s=%c \n", casa.c_str(),pieceForCase);
            
        }
        
        EndDrawing();
    }
    


    return 0;
}

//g++ main.cpp -o main.exe -I"D:/raylib/src" -L"D:/raylib/build/raylib" -lraylib -lopengl32 -lgdi32 -lwinmm {windows}
// g++ main.cpp -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 {linux}

//g++ main.cpp -o /home/vinicius-pc/exe/chess/src/main -I//home/vinicius-pc/raylib/build/raylib/include/ -L/home/vinicius-pc/raylib/build/raylib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11