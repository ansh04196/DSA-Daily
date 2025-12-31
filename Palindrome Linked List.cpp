class Solution {
  isPalindrome(head) {
    if (head === null || head.next === null) {
      return true;
    }

    let slow = head;
    let fast = head;

    while (fast !== null && fast.next !== null) {
      slow = slow.next;
      fast = fast.next.next;
    }

    let prev = null;
    let current = slow;

    while (current !== null) {
      let nextNode = current.next;
      current.next = prev;
      prev = current;
      current = nextNode;
    }

    let firstHalf = head;
    let secondHalf = prev;

    while (secondHalf !== null) {
      if (firstHalf.data !== secondHalf.data) {
        return false;
      }
      firstHalf = firstHalf.next;
      secondHalf = secondHalf.next;
    }

    current = prev;
    prev = null;
    while (current !== null) {
      let nextNode = current.next;
      current.next = prev;
      prev = current;
      current = nextNode;
    }

    return true;
  }
}
Today POTD Solution,
Code in js
