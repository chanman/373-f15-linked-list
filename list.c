#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {

	assert(head != NULL);
	assert(new_element != NULL);
	list_t* pointed = head;
	int compared= pointed->index;
	list_t* prev = NULL;

	while(new_element->index > compared && pointed->next!=NULL){
		prev= pointed;
		pointed= pointed->next;
		compared = pointed->index;
	}

	if(pointed->next==NULL){
		if(new_element->index > pointed->index){
			pointed->next=new_element;
			new_element->next=NULL;
		}
		else{
			prev->next = new_element;
			new_element->next=pointed;
		}
	}

	else{
		new_element->next = pointed;
		if(prev!= NULL){
			prev->next= new_element;
		}
	}



	if(new_element->next == head){
		head= new_element;
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* prev;
	list_t* next;
	prev=head;
	if(head->next==NULL){
		return; //do nothing if list of length 1
	}

	head=head->next;
	prev->next=NULL;
	next=head->next;
	head->next=prev;

	while(next != NULL){
		prev=head;
		head=next;
		next= head->next;
		head->next=prev;
	}

	return head;
}

