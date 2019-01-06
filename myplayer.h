



bool Player::isCheck(){
	for(int i=0; i < chess.size(); ++i) {
		if(chess[i]->get_name() == 'k' || chess[i]->get_name() == 'K') { //chess is king
			int x = chess[i]->getX();
			int y = chess[i]->getY();
		
			for(int j=0; j < p2->get_pieces.size(); ++j) {//assume all cheess in peice are alive
				if(p2->get_pieces[j]->getAlive() && p2->get_pieces[j]->attack(x, y)) { //piece is alive
					if(!p2->get_pieces[j]->isblock(x,y)) return true;
				}
		    }
		}
	}
	return false;
}

bool Player::isCheck2(int x, int y) { //true if king in (x,y) is in check, false otherwise
	for(int j=0; j < p2->get_pieces.size(); ++j) {//assume all cheess in peice are alive
		if(p2->get_pieces[j]->getAlive() && p2->get_pieces[j]->attack(x, y)) { //piece is alive
			if(!p2->get_pieces[j]->isblock(x,y)) return true;
		}
	}
	return false;
}

bool Player::isCheckmate() { 
	if(!this->isCheck) return false; //king is not in check

	vector<vector<int>> move;
	for(int i=0; i < chess.size(); ++i) {
		//piece is king
		if(chess[i]->get_name() == 'k' || chess[i]->get_name() == 'K') { 
			move = chess[i]->getNext_move(); // possible move
			for(int j=0; j < move.size(); ++j) {
				//king can move to a cell that not in check
				if(!chess[i]->isCheck2(move[j][0], move[j][1])) return false;
			}
		}

		//if king has no possible move but can move other piece to block the attack
		if((!this->checkAfterMove(chess[i]))) return false;
	}
}


bool Player::ifCastling(Piece *k, Piece *r) { //return true if k and rook can castling, otherwise false
	if(!k->get_FirstMove()) return false; //king has been moved
	if(!r->get_FirstMove()) return false; //rook has been moved
	int x = k->getX();
	int y = k->getY();
	if(r->isblock(x, y)) return false; //there are pieces standing bewteen the king and rook
	if(isCheck2(x, y)) return false; // king is in check
    x = x < r->getX() ? x + 2 : x - 2; //king's position after castling
    if(isCheck2(x,y)) return false; // king will be in check after castling
    return true;
}

bool Player::isStalemate() {
	if(this->isCheck) return false; // king is in check

	for(int i=0; i < chess.size(); ++i) {
		if(chess[i]->getAlive) { //all alive pieces
			//piece is king
			if(chess[i]->get_name() == 'k' || chess[i]->get_name() == 'K') { 
				vector<vector<int>> move = chess[i]->getNext_move(); // possible move

				for(int j=0; j < move.size(); ++j) {
					//king can move to a cell that not in check
					if(!chess[i]->isCheck2(move[j][0], move[j][1])) return false;
				}
				for(int k=0; k < chess.size(); ++k) {
					if((chess[k]->get_name() == 'r' || chess[k]->get_name() == 'R')
					 && chess[k]->getAlive() && ifCastling(chess[i], chess[k])) {
						 return false; //can castling
					}
				}
			}

			//other piece except king
			else { 
				//whether piece can move to a cell that not let k in check
				if(!this->checkAfterMove(chess[i])) return false;
			}

		}
	}
	return true;
}

bool Player::checkAfterMove(Piece *p) { //return true if k will be in check after p moves, otherwise false
	vector<vector<int> move = p->getNext_move;
	bool check = false;
	for(int i=0; i < move.size; ++i) {
		int x = move[i][0];
		int y = move[i][1];
		int x_prev = p->getX_prev();
		int y_prev = p->getY_prev();
		//move p
		p->SetX_prev(p->getX());
	    p->SetX_prev(p->getY());
		p->SetX(x);
		p->SetY(y);
	    
		if(this->isCheck()) {
			check = true;
		}

		//restore p
		p->SetX(p->getX_prev());
		p->SetY(p->getY_prev());
		p->SetX_prev(x_prev);
		p->Sety_prev(y-prev);

		if(check) break;
	}
	if(check) return true;
	return false;
}