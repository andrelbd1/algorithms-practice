#
# Complete the 'reverse' function below.
#
# The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
# The function accepts INTEGER_DOUBLY_LINKED_LIST llist as parameter.
#

#
# For your reference:
#
# DoublyLinkedListNode:
#     int data
#     DoublyLinkedListNode next
#     DoublyLinkedListNode prev
#
#

def reverse(llist):
    if llist.next is None:
        return llist
    else:
        curr = llist
        curr_newList = DoublyLinkedListNode(curr.data)
        curr_newList.next = None
        while True:
            if curr.next is None:
                break
            curr_newList.prev = DoublyLinkedListNode(curr.next.data)
            curr_newList.prev.next = curr_newList
            curr_newList = curr_newList.prev
            curr = curr.next
        
    return curr_newList