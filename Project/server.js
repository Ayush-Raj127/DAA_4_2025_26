const express = require('express');
const cors = require('cors');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3000;

app.use(express.json());
// Serve static frontend
app.use(express.static(path.join(__dirname, 'public')));

// Linked List logic
class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    append(value) {
        const newNode = new Node(value);
        if (!this.head) {
            this.head = newNode;
            return;
        }
        let current = this.head;
        while (current.next) {
            current = current.next;
        }
        current.next = newNode;
    }

    prepend(value) {
        const newNode = new Node(value);
        newNode.next = this.head;
        this.head = newNode;
    }

    pop() {
        if (!this.head) return null;
        if (!this.head.next) {
            const val = this.head.value;
            this.head = null;
            return val;
        }
        let current = this.head;
        while (current.next.next) {
            current = current.next;
        }
        const val = current.next.value;
        current.next = null;
        return val;
    }

    shift() {
        if (!this.head) return null;
        const val = this.head.value;
        this.head = this.head.next;
        return val;
    }

    toArray() {
        const arr = [];
        let current = this.head;
        while (current) {
            arr.push(current.value);
            current = current.next;
        }
        return arr;
    }
}

const list = new LinkedList();

// Initialize with some dummy data
list.append("Head");
list.append("Node 1");
list.append("Tail");

// API Routes
app.get('/api/list', (req, res) => {
    res.json(list.toArray());
});

app.post('/api/list/append', (req, res) => {
    const { value } = req.body;
    if (value) list.append(value);
    res.json(list.toArray());
});

app.post('/api/list/prepend', (req, res) => {
    const { value } = req.body;
    if (value) list.prepend(value);
    res.json(list.toArray());
});

app.delete('/api/list/pop', (req, res) => {
    list.pop();
    res.json(list.toArray());
});

app.delete('/api/list/shift', (req, res) => {
    list.shift();
    res.json(list.toArray());
});

app.listen(PORT, () => {
    console.log(`DSA Visualizer Server running on http://localhost:${PORT}`);
});
