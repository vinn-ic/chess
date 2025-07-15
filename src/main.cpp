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

        if(!casa.empty()){
            DrawRectangle(pgn[casa].x,pgn[casa].y,100,100,YELLOW);
            PieceCaseMove = casa;
            pedra = pgnForPieces[casa];
            
            if(isWhiteMove){//arrumar isso depois esses whitch e ifs do iswhitemove
                switch(pieceForCase){
                    case 'P': {
                        auto it = pgn.find(casa);
                        if (it != pgn.end() ){
                            if(casa[0] > 'A' && casa[1] < '8'){
                                string diagEsq = string(1, casa[0] - 1) + string(1,casa[1] + 1);
                                if(pgn.count(diagEsq) > 0 && pgnForPieces[diagEsq] != '_' && islower(pgnForPieces[diagEsq])){
                                    casasAlvos.push_back(diagEsq);
                                }
                            }
                            if(casa[0] < 'H' && casa[1] < '8'){
                                string diagDir = string(1, casa[0]+1) + string(1,casa[1]+1);
                                if(pgn.count(diagDir) > 0&& pgnForPieces[diagDir] != '_' && islower(pgnForPieces[diagDir])){
                                    casasAlvos.push_back(diagDir);
                                }
                            }
                           
                            it++;
                            if(pgnForPieces[it->first] == '_'){

                                if(find(casasAlvos.begin(), casasAlvos.end(), it->first.c_str()) == casasAlvos.end()){
                                    //casasAlvos.clear();
                                    casasAlvos.push_back(it->first.c_str());
                                }
                                if(it != pgn.end() && casa[1] == '2'){
                                    it++;
                                    if(find(casasAlvos.begin(), casasAlvos.end(), it->first.c_str()) == casasAlvos.end()){
                                        casasAlvos.push_back(it->first.c_str());
                                    }
                                }
                            }
                        }
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
                }//fim switch branco!!!!!!!!
            }else if(!isWhiteMove){
                switch(pieceForCase){
                    case 'p': {
                        auto it = pgn.find(casa);
                        if (it != pgn.end()){
                            it--;
                            if (it != pgn.end()) {

                                if (casa[0] > 'A' && casa[1] > '1') {
                                    string diagEsq = string(1, casa[0] - 1) + string(1, casa[1] - 1);
                                    if (pgn.count(diagEsq) > 0 && pgnForPieces[diagEsq] != '_' && isupper(pgnForPieces[diagEsq])) {
                                        casasAlvos.push_back(diagEsq);

                                    }
                                }
                            
                                if (casa[0] < 'H' && casa[1] > '1') {
                                    string diagDir = string(1, casa[0] + 1) + string(1, casa[1] - 1);
                                    if (pgn.count(diagDir) > 0 && pgnForPieces[diagDir] != '_' && isupper(pgnForPieces[diagDir])) {
                                        casasAlvos.push_back(diagDir);

                                    }
                                }
                            }

                            if(pgnForPieces[it->first] == '_'){    
                                if(it != pgn.end()){
                                    if(find(casasAlvos.begin(), casasAlvos.end(), it->first.c_str()) == casasAlvos.end()){
                                        //casasAlvos.clear();//ver isso depois eu acho que esta com dados furados aqui !!!! ver esses ifs ai
                                        casasAlvos.push_back(it->first.c_str());
                                    }
                                    it--;
                                    if(it != pgn.end() && casa[1] ==  '7'){
                                        if(find(casasAlvos.begin(), casasAlvos.end(), it->first.c_str()) == casasAlvos.end()){
                                            casasAlvos.push_back(it->first.c_str());
                                            
                                        }
                                    }
                                }
                            }
                        } 
                    
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
        
        for(string& alvos : casasAlvos){
            DrawRectangle(pgn[alvos].x,pgn[alvos].y,100,100,YELLOW_LIGHT);
        }

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
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
                    printf("click>> %s=%c\n", casa.c_str(), pgnForPieces[casa]);
                    cout << casasAlvos.size() << " size\n";
                    pgnForPieces[PieceCaseMove] = '_';
                    pgnForPieces[casa] = pedra;

                    PieceCaseMove = "";
                    isWhiteMove = !isWhiteMove;
                    casasAlvos.clear();
                    casa = "";
                    cout << "olooiioioioioiioo" << "\n";
                }else if(!isAMove){
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
        EndDrawing();
    }
    


    return 0;
}

//g++ main.cpp -o main.exe -I"D:/raylib/src" -L"D:/raylib/build/raylib" -lraylib -lopengl32 -lgdi32 -lwinmm {windows}
// g++ main.cpp -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 {linux}

//g++ main.cpp -o /home/vinicius-pc/exe/chess/src/main -I//home/vinicius-pc/raylib/build/raylib/include/ -L/home/vinicius-pc/raylib/build/raylib/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
