package structs;

// Definition for singly-linked list.
public class ListNode {
    public int val;
    public ListNode next;

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

    @Override
    public String toString() {
        return String.valueOf(this.val) + " -> " + (this.next == null ? "null" : this.next.toString());
    }
}
