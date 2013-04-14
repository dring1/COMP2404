Node *temp = front;

while(temp!=0)
{
	if(temp->getData()==&data){
		if(temp==front){
			delete temp;
			front = front->getNext();
		}
			
	}else if(temp->getNext()->getData()==&data){
		if(temp->getNext()->getNext()==0){
			delete temp;
			break;
		}else{
			delete temp->getNext();
			temp->setNext(temp->getNext()-getNext());
		}
	}
	temp = temp->getNext();
}



while(temp->getNext()!=0){
		if(front->getData()==&data ){//base case for checking if first node is the node to be removed
			cout<<"Pow"<<endl;
			temp = front;
			//front->setNext(0);
			
			front = front->getNext();
			//delete temp;
			size--;
		}
		else if(temp->getNext()->getData()==&data){//if the next node is the node to be deleted then 
			
			if (temp->getNext()==current)
			{
				temp->setNext(0);
				delete current;
				current = temp;
			}
			else{
				temp->setNext(temp->getNext()->getNext());//join this next node with next->next hoping over next
			}
			size--;
		}
		if(temp->getNext()!=0)
			temp = temp->getNext();
	}


	List &List::operator-=(Pirate & data)
{
	Node *temp = front;

	while(temp!=0){
			cout<<"Cats"<<endl;
			if(front->getData()==&data ){//base case for checking if first node is the node to be removed
				temp = front;
				if(front->getNext()!=0)		
					front = front->getNext();
				delete temp;
				size--;
			}
			else if(temp->getNext()!=0&&temp->getNext()->getData()==&data){//if the next node is the node to be deleted then 		
				if (temp->getNext()==current)
				{
					temp = 0;
					current = temp;
				}
				else{
					if(temp->getNext()->getNext()!=0)
						temp->setNext(temp->getNext()->getNext());//join this next node with next->next hoping over next
				}
				size--;
			}
			if(temp->getNext()!=0){
				temp = temp->getNext();
			}
			else 
				break;
	}
	/*if(temp->getNext()==0&&temp->getData()==&data){
		if(temp == current && size==0){
			cout<<"pew"<<endl;
			front = 0;
			temp = 0;
			//current = 0;
		}
		 
	}*/
		
	return *this;
}