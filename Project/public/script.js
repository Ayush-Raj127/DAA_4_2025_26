const apiUrl = '/api/list';
const visualizationArea = document.getElementById('visualization-area');
const nodeInput = document.getElementById('node-value');

// Fetch initial list
async function fetchList() {
    try {
        const res = await fetch(apiUrl);
        const data = await res.json();
        renderList(data);
    } catch (e) {
        console.error("Failed to fetch list", e);
    }
}

// Render list dynamically
function renderList(nodes) {
    visualizationArea.innerHTML = '';
    
    if (nodes.length === 0) {
        visualizationArea.innerHTML = '<div class="null-node">List is empty (null)</div>';
        return;
    }

    nodes.forEach((val, index) => {
        // Create container for node + arrow
        const container = document.createElement('div');
        container.className = 'node-container';
        // Staggered animation
        container.style.animationDelay = `${index * 0.1}s`;

        // Create node
        const nodeDiv = document.createElement('div');
        nodeDiv.className = 'list-node';
        nodeDiv.innerText = val;
        
        container.appendChild(nodeDiv);

        // Create arrow
        const arrowDiv = document.createElement('div');
        arrowDiv.className = 'arrow';
        if (index === nodes.length - 1) {
            arrowDiv.innerHTML = '<span class="null-node">null</span>';
        } else {
            arrowDiv.innerText = '→';
        }
        container.appendChild(arrowDiv);

        visualizationArea.appendChild(container);
    });
}

// Actions
async function operate(action, method) {
    const val = nodeInput.value.trim();
    if (method === 'POST' && !val) {
        alert("Please enter a value!");
        return;
    }

    try {
        const options = {
            method: method,
            headers: { 'Content-Type': 'application/json' }
        };
        if (method === 'POST') {
            options.body = JSON.stringify({ value: val });
        }

        const res = await fetch(`${apiUrl}/${action}`, options);
        if (res.ok) {
            const data = await res.json();
            renderList(data);
            nodeInput.value = '';
        }
    } catch (e) {
        console.error(`Error performing ${action}`, e);
    }
}

function appendNode() { operate('append', 'POST'); }
function prependNode() { operate('prepend', 'POST'); }
function popNode() { operate('pop', 'DELETE'); }
function shiftNode() { operate('shift', 'DELETE'); }

// Init
nodeInput.addEventListener('keypress', function (e) {
    if (e.key === 'Enter') {
        appendNode();
    }
});

fetchList();
