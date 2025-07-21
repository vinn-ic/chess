#include "raylib.h"
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

class Pieces{
    public:
        
        Texture2D T;
        map<string,Vector2> pgn;
        map<string, char> pgnForrrPieces;
        char piece;

        Pieces( Texture2D T, map<string,Vector2> pgn, map<string, char>& pgnForrrPieces,char piece){
            this->T = T;
            this->pgn = pgn;
            this->pgnForrrPieces = pgnForrrPieces;
            this->piece = piece;
        }
        void DrawP(map<string,char>& pgnForPieces){
            
            for(auto& pgnFP : pgnForPieces){
                if(pgnFP.second == piece){
                    DrawTexture(T, pgn[pgnFP.first].x,pgn[pgnFP.first].y,WHITE);
                }
            }
        }
        

        
        
};

Color YELLOW_LIGHT = {255, 255, 153, 255};
Color GREEN_LIGHT =  {40, 40, 40, 255};




bool WhiteRookRigthIsMove = false;
bool WhiteRookLeftIsMove = false;
bool BlackRookRigthIsMove = false;
bool BlackRookLeftIsMove = false;

bool WhiteKingIsMove = false;
bool BlackKingIsMove = false;

bool KingBlackIsDeath = false;
bool KingWhiteIsDeath = false;
bool RunChess = true;

int main(){
    string PieceCaseMove;
    char pedra;
    bool isWhiteMove = true;
    string casa;
    vector<string> casasAlvos;
    bool apagaressamerda = false; 

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
            if(key[1] == '2') {
                pgnForPieces[key] = 'P';
            } else if(key[1] == '7') {
                pgnForPieces[key] = 'p';
            } else if(key == "A1" || key == "H1") {
                pgnForPieces[key] = 'T';
            } else if(key == "A8" || key == "H8") {
                pgnForPieces[key] = 't';
            } else if(key == "B1" || key == "G1") {
                pgnForPieces[key] = 'C';
            } else if(key == "B8" || key == "G8") {
                pgnForPieces[key] = 'c';  
            } else if(key == "C1" || key == "F1") {
                pgnForPieces[key] = 'B';  
            } else if(key == "C8" || key == "F8") {
                pgnForPieces[key] = 'b';
            } else if(key == "D1") {
                pgnForPieces[key] = 'D';  
            } else if(key == "D8") {
                pgnForPieces[key] = 'd'; 
            } else if(key == "E1") {
                pgnForPieces[key] = 'R';
            } else if(key == "E8") {
                pgnForPieces[key] = 'r';  
            } else {
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

    Pieces Pawn(Tp,pgn, pgnForPieces,'P');
    Pieces Queen(TQ,pgn, pgnForPieces,'D');
    Pieces King(TK,pgn, pgnForPieces,'R');
    Pieces vacalo(TH,pgn,pgnForPieces,'C');
    Pieces papa(TB,pgn,pgnForPieces,'B');
    Pieces TorresGemeas(TT, pgn,pgnForPieces,'T');

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

    Pieces PawnBlack(TpBlack, pgn,pgnForPieces,'p');
    Pieces QueenBlack(TQBlack, pgn,pgnForPieces,'d');
    Pieces KingBlack(TKBlack, pgn,pgnForPieces,'r');
    Pieces vacaloBlack(THBlack, pgn,pgnForPieces,'c');
    Pieces papaBlack( TBBlack, pgn,pgnForPieces,'b');
    Pieces TorresGemeasBlack(TTBlack, pgn,pgnForPieces,'t');

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

        if(!casa.empty() && RunChess){
            DrawRectangle(pgn[casa].x,pgn[casa].y,100,100,YELLOW);
            PieceCaseMove = casa;
            pedra = pgnForPieces[casa];
            
            if(isWhiteMove){//arrumar isso depois esses whitch e ifs do iswhitemove
                switch(pieceForCase){
                    case 'P': {
                        char col = casa[0];
                        char lin = casa[1];
                        string nextDigDir = string(1,col+1) + string(1,lin+1);
                        string nextDigEsq = string(1, col-1) + string(1,lin+1);
                        string nextPos1 = string(1, col) + string(1,lin+1);

                        if(pgnForPieces[nextDigDir] != '_' && islower(pgnForPieces[nextDigDir])) casasAlvos.push_back(nextDigDir);
                        if(pgnForPieces[nextDigEsq] != '_' && islower(pgnForPieces[nextDigEsq])) casasAlvos.push_back(nextDigEsq);

                        if(lin == '2'){
                            for(char l = lin+1;l <= '4'; l++){
                                string nextPos = string(1,col) + string(1, l);
                                if(pgnForPieces[nextPos] == '_' && pgnForPieces[nextPos1] == '_'){
                                    casasAlvos.push_back(nextPos);
                                   // pgnForPieces[nextPos] = '&';
                                }
                            
                            }

                        }if(pgnForPieces[nextPos1] == '_') if(pgnForPieces[nextPos1] == '_') casasAlvos.push_back(nextPos1);

                    
                    break;
                    }
                    case 'T': {
                        char col = casa[0];
                        char lin = casa[1];

                        for(char r = lin + 1; r <= '8';r++){
                            string nextPos = string(1, col) + string(1, r);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char r = lin-1; r >= '1'; r--){
                            string nextPos = string(1, col) + string(1, r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col + 1; col <= 'H'; c++){//poggers!!!!
                            string nextPos = string(1, c) + string(1, lin);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col-1;col >= 'A'; c--){
                            string nextPos = string(1,c)+string(1,lin);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 'B':{
                        char col = casa[0];
                        char lin = casa[1];


                        for(char c = col +1,r = lin + 1; c <= 'H' && r <= '8'; c++, r++){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col -1,r = lin + 1; c <= 'H' && r <= '8'; c--, r++){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col +1,r = lin - 1; c <= 'H' && r <= '8'; c++, r--){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col -1,r = lin - 1; c <= 'H' && r <= '8'; c--, r--){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }

                        break;
                    }
                    case 'C': {
                        char col = casa[0];
                        char lin = casa[1];

                        int colCavalo[] = {1,1,2,2,-1,-1,-2,-2};
                        int linCavalo[] = {2,-2,1,-1,2,-2,1,-1};

                        for(int i = 0;i < 8;i++){
                            char nextCol = col + colCavalo[i];
                            char nextLin = lin + linCavalo[i];

                            if(nextCol >= 'A' && nextCol <= 'H' && nextLin >= '1' && nextLin <= '8'){
                                string nextPos = string(1, nextCol) + string(1, nextLin);
                                if(pgnForPieces[nextPos] == '_' || islower(pgnForPieces[nextPos])) casasAlvos.push_back(nextPos);
                            }
                        }

                        break;
                    }
                    case 'D': {
                        char col = casa[0];
                        char lin = casa[1];

                        //lados \|/
                          for(char r = lin + 1; r <= '8';r++){
                            string nextPos = string(1, col) + string(1, r);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char r = lin-1; r >= '1'; r--){
                            string nextPos = string(1, col) + string(1, r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col + 1; col <= 'H'; c++){//poggers!!!!
                            string nextPos = string(1, c) + string(1, lin);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col-1;col >= 'A'; c--){
                            string nextPos = string(1,c)+string(1,lin);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }


                        //diagonais \|/
                        for(char c = col +1,r = lin + 1; c <= 'H' && r <= '8'; c++, r++){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col -1,r = lin + 1; c <= 'H' && r <= '8'; c--, r++){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col +1,r = lin - 1; c <= 'H' && r <= '8'; c++, r--){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col -1,r = lin - 1; c <= 'H' && r <= '8'; c--, r--){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(islower(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 'R': {
                        char col = casa[0];
                        char lin = casa[1];

                        for(int dx = -1;dx <=1;dx++){
                            for(int dy = -1;dy <=1;dy++){
                                if(dx == 0 && dy == 0) continue;

                                char newCol = col + dx;
                                char newLin = lin + dy;

                                if(newCol >= 'A' && newCol <= 'H' && newLin >= '1' && newLin <= '8' ){
                                    string nextPos = string(1, newCol)+string(1,newLin);

                                    if(islower(pgnForPieces[nextPos]) || pgnForPieces[nextPos] == '_'){
                                        casasAlvos.push_back(nextPos);
                                    }
                                }
                            }
                        }
                        if(!WhiteKingIsMove){
                            if(!WhiteRookRigthIsMove && pgnForPieces["F1"] == '_' && pgnForPieces["G1"] == '_'){
                                casasAlvos.push_back("G1");
                            }
                            if(!WhiteRookLeftIsMove && pgnForPieces["D1"] == '_' && pgnForPieces["C1"] == '_' && pgnForPieces["B1"] == '_'){
                                casasAlvos.push_back("C1");
                            }
                        }

                            
                        
                       

                        break;
                    }
                }//fim switch branco!!!!!!!!
            }else if(!isWhiteMove){
                switch(pieceForCase){
                    case 'p': {
                        char col = casa[0];
                        char lin = casa[1];
                        string nextDigDir = string(1,col-1) + string(1,lin-1);
                        string nextDigEsq = string(1, col+1) + string(1,lin-1);
                        string nextPos1 = string(1, col) + string(1,lin-1);

                        if(pgnForPieces[nextDigDir] != '_' && isupper(pgnForPieces[nextDigDir])) casasAlvos.push_back(nextDigDir);
                        if(pgnForPieces[nextDigEsq] != '_' && isupper(pgnForPieces[nextDigEsq])) casasAlvos.push_back(nextDigEsq);

                        if(lin == '7'){
                            for(char l = lin-1;l >= '5'; l--){
                                string nextPos = string(1,col) + string(1, l);
                                if(pgnForPieces[nextPos] == '_' && pgnForPieces[nextPos1] == '_'){
                                    casasAlvos.push_back(nextPos);
                                    //pgnForPieces[nextPos] = '&';
                                }
                            
                            }

                        }if(pgnForPieces[nextPos1] == '_') if(pgnForPieces[nextPos1] == '_') casasAlvos.push_back(nextPos1);

                    
                    
                        break;
                    }


                    case 't':{
                        char col = casa[0];
                        char lin = casa[1];

                        for(char r = lin + 1; r <= '8';r++){
                            string nextPos = string(1, col) + string(1, r);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char r = lin-1; r >= '1'; r--){
                            string nextPos = string(1, col) + string(1, r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col + 1; col <= 'H'; c++){//poggers!!!!
                            string nextPos = string(1, c) + string(1, lin);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col-1;col >= 'A'; c--){
                            string nextPos = string(1,c)+string(1,lin);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 'b': {
                        char col = casa[0];
                        char lin = casa[1];


                        for(char c = col +1,r = lin + 1; c <= 'H' && r <= '8'; c++, r++){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col -1,r = lin + 1; c <= 'H' && r <= '8'; c--, r++){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col +1,r = lin - 1; c <= 'H' && r <= '8'; c++, r--){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col -1,r = lin - 1; c <= 'H' && r <= '8'; c--, r--){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        
                        break;
                    }
                    case 'c': {
                        char col = casa[0];
                        char lin = casa[1];

                        int colCavalo[] = {1,1,2,2,-1,-1,-2,-2};
                        int linCavalo[] = {2,-2,1,-1,2,-2,1,-1};

                        for(int i = 0;i < 8;i++){
                            char nextCol = col + colCavalo[i];
                            char nextLin = lin + linCavalo[i];

                            if(nextCol >= 'A' && nextCol <= 'H' && nextLin >= '1' && nextLin <= '8'){
                                string nextPos = string(1, nextCol) + string(1, nextLin);
                                if(pgnForPieces[nextPos] == '_' || isupper(pgnForPieces[nextPos])) casasAlvos.push_back(nextPos);
                            }
                        }


                        break;
                    }
                    case 'd': {
                        char col = casa[0];
                        char lin = casa[1];

                        //lados \|/
                          for(char r = lin + 1; r <= '8';r++){
                            string nextPos = string(1, col) + string(1, r);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char r = lin-1; r >= '1'; r--){
                            string nextPos = string(1, col) + string(1, r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col + 1; col <= 'H'; c++){//poggers!!!!
                            string nextPos = string(1, c) + string(1, lin);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col-1;col >= 'A'; c--){
                            string nextPos = string(1,c)+string(1,lin);
                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }


                        //diagonais \|/
                        for(char c = col +1,r = lin + 1; c <= 'H' && r <= '8'; c++, r++){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col -1,r = lin + 1; c <= 'H' && r <= '8'; c--, r++){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col +1,r = lin - 1; c <= 'H' && r <= '8'; c++, r--){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }
                        for(char c = col -1,r = lin - 1; c <= 'H' && r <= '8'; c--, r--){
                            string nextPos = string(1,c) + string(1,r);

                            if(pgnForPieces[nextPos] == '_'){
                                casasAlvos.push_back(nextPos);
                            }else{
                                if(isupper(pgnForPieces[nextPos])){
                                    casasAlvos.push_back(nextPos);
                                }
                                break;
                            }
                        }


                        break;
                    }
                    case 'r': {
                        char col = casa[0];
                        char lin = casa[1];

                        for(int dx = -1;dx <=1;dx++){
                            for(int dy = -1;dy <=1;dy++){
                                if(dx == 0 && dy == 0) continue;

                                char newCol = col + dx;
                                char newLin = lin + dy;

                                if(newCol >= 'A' && newCol <= 'H' && newLin >= '1' && newLin <= '8' ){
                                    string nextPos = string(1, newCol)+string(1,newLin);

                                    if(isupper(pgnForPieces[nextPos]) || pgnForPieces[nextPos] == '_'){
                                        casasAlvos.push_back(nextPos);
                                    }
                                }
                            }
                        }

                        if(!BlackKingIsMove){
                            if(!BlackRookLeftIsMove && pgnForPieces["F8"] == '_' && pgnForPieces["G8"] == '_'){
                                casasAlvos.push_back("G8");
                            }if(!BlackRookRigthIsMove && pgnForPieces["D8"] == '_' && pgnForPieces["C8"] == '_' && pgnForPieces["C8"] == '_'){
                                casasAlvos.push_back("C8");
                            }
                        }

                        break;
                    }

                }
            }
            //for(auto& casa : casasAlvos){
             //   printf("casas alvos>> %s\n", casa.c_str());
            //}
             if(!apagaressamerda){

                copy(casasAlvos.begin(), casasAlvos.end(), ostream_iterator<string>(cout, " "));
                apagaressamerda = true;
            }

           
        }   

        Vector2 posMouse = GetMousePosition();

         for(string& alvos : casasAlvos){
            DrawRectangle(pgn[alvos].x,pgn[alvos].y,100,100,YELLOW_LIGHT);
            cout << casasAlvos.size() << "\n";
        }

        Pawn.DrawP(pgnForPieces);
        Queen.DrawP(pgnForPieces);
        King.DrawP(pgnForPieces);
        vacalo.DrawP(pgnForPieces);
        papa.DrawP(pgnForPieces);
        TorresGemeas.DrawP(pgnForPieces);
        //
        PawnBlack.DrawP(pgnForPieces);
        QueenBlack.DrawP(pgnForPieces);
        KingBlack.DrawP(pgnForPieces);
        vacaloBlack.DrawP(pgnForPieces);
        papaBlack.DrawP(pgnForPieces);
        TorresGemeasBlack.DrawP(pgnForPieces);
    

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && RunChess){
            float x = posMouse.x;
            float y = posMouse.y;
            //string clickCasa;//
            bool clickFound = false;
            

            for(auto& cord : pgn){
                float cx = cord.second.x;
                float cy = cord.second.y;
                
                if(abs((cx+50) - x) <= 50 && abs((cy + 50) - y) <= 50){
                    casa = cord.first.c_str();
                    clickFound = true;
                    break;
                }
            }
            if(clickFound){
                bool isAMove = (find(casasAlvos.begin(), casasAlvos.end(), casa) != casasAlvos.end());
            
                if(isAMove){
                    if(pgnForPieces[casa] == 'R') KingWhiteIsDeath = true;
                    if(pgnForPieces[casa] == 'r') KingBlackIsDeath = true;
                    if(KingBlackIsDeath || KingWhiteIsDeath) RunChess = false;

                    if(pedra == 'R' && casa == "C1"){
                        pgnForPieces["E1"] = '_';
                        pgnForPieces["A1"] = '_';
                        pgnForPieces["C1"] = 'R';
                        pgnForPieces["D1"] = 'T';
                        WhiteKingIsMove = true;
                        WhiteRookLeftIsMove = true;
                    }if(pedra == 'R' && casa == "G1"){
                        pgnForPieces["E1"] = '_';
                        pgnForPieces["H1"] = '_';
                        pgnForPieces["G1"] = 'R';
                        pgnForPieces["F1"] = 'T';
                        WhiteKingIsMove = true;
                        WhiteRookRigthIsMove = true;
                    }if(pedra == 'r' && casa == "G8"){
                        pgnForPieces["E8"] = '_';
                        pgnForPieces["H8"] = '_';
                        pgnForPieces["G8"] = 'r';
                        pgnForPieces["F8"] = 't';
                        BlackRookLeftIsMove = true;
                        BlackKingIsMove = true;
                    }if(pedra == 'r'&& casa == "C8"){
                        pgnForPieces["E8"] = '_';
                        pgnForPieces["A8"] = '_';
                        pgnForPieces["C8"] = 'r';
                        pgnForPieces["D8"] = 't';
                        BlackRookRigthIsMove = true;
                        BlackKingIsMove = true;
                    }
                        
                        printf("click>> %s=%c\n", casa.c_str(), pgnForPieces[casa]);
                        cout << casasAlvos.size() << " size\n";
                        pgnForPieces[PieceCaseMove] = '_';
                        
                        pgnForPieces[casa] = pedra;

                        if(pedra == 'r') BlackKingIsMove = true;
                        if(pedra == 'R') WhiteKingIsMove = true;
                        
                        PieceCaseMove = "";
                        isWhiteMove = !isWhiteMove;
                        casasAlvos.clear();
                        casa = "";
                        cout << "olooiioioioioiioo" << "\n";

                    }if(!isAMove){
                        char selectedP = pgnForPieces[casa];
                        if((isWhiteMove && isupper(selectedP)) || (!isWhiteMove && islower(selectedP))){
                            pieceForCase = selectedP;
                            casasAlvos.clear();
                            apagaressamerda = false;
                            printf("click>> %s=%c\n", casa.c_str(), pieceForCase);
                        }else{
                            casa = "";
                            casasAlvos.clear();
                        }
                    }   
                }
        }
        sort(casasAlvos.begin(), casasAlvos.end());
        auto fimUnicos = unique(casasAlvos.begin(), casasAlvos.end());
        casasAlvos.erase(fimUnicos, casasAlvos.end());

        
        if(!RunChess){
            string texto = "ERRO[ERRO[ERRO[EROO]]]";
            if(KingWhiteIsDeath) texto = "Vitória das pretas!";
            if(KingBlackIsDeath) texto = "Vitória das brancas!";

            DrawRectangle(telaX/8,telaY/4,600,400,GREEN_LIGHT);
            DrawText(texto.c_str(),telaX/2,telaY/2,35,BLACK);
        }
        EndDrawing();
    }
    
    return 0;
}