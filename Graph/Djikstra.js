class PriorityQueue{
    constructor() {
        this.values = [];
    }

    enqueue(val,priority) {
        this.values.push({val,priority});
        this.sort();
    }

    dequeue() {
        return this.values.shift();
    }

    sort() {
        this.values.sort((a,b)  => a.priority - b.priority);
    }
}



class WeightedGraph {
    constructor() {
        this.adjacencyList =  {};
    }

    addVertex(vert) {
        if(!this.adjacencyList[vert]) {
            this.adjacencyList[vert] = [];
        }
    }

    addEdge(vert1,vert2,weight) {
       this.adjacencyList[vert1].push({node:vert2,weight});
       this.adjacencyList[vert2].push({node:vert1,weight});
    }

    Dijkstra(start,finish)  {
        const nodes = new PriorityQueue();
        const distances = {};
        const previous = {};
        let path = [];
        let smallest;
        for(let vertex in this.adjacencyList) {
            if(vertex === start) {
                distances[vertex] = 0;
                nodes.enqueue(vertex,0);
            } else {
                distances[vertex] = Infinity;
                nodes.enqueue(vertex,Infinity);
            }
            previous[vertex] = null;
        }

        while(nodes.values.length) {
            smallest = nodes.dequeue().val;
            if(smallest === finish) {
                while(previous[smallest]) {
                    path.push(smallest);
                    smallest = previous[smallest];
                }
                break;
            }
            if(distances[smallest] !== Infinity) {
            for(let neighbor in this.adjacencyList[smallest]) {
                let nextNode = this.adjacencyList[smallest][neighbor];
                let candidate = distances[smallest] + nextNode.weight;
                let nextneighbor = nextNode.node;
                if(candidate < distances[nextneighbor]) {
                    distances[nextneighbor] = candidate;
                    previous[nextneighbor] = smallest;
                    nodes.enqueue(nextneighbor,candidate);
                }
            }
        }
        }
        return path.concat(smallest).reverse();
    }
}

let list = new WeightedGraph();
list.addVertex("A");
list.addVertex("B");
list.addVertex("C");
list.addVertex("D");
list.addVertex("E");
list.addVertex("F");
list.addEdge("A","B",4);
list.addEdge("A","C",2);
list.addEdge("B","E",3);
list.addEdge("C","D",2);
list.addEdge("C","F",4);
list.addEdge("D","E",3);
list.addEdge("D","F",1);
list.addEdge("E","F",1);
list.Dijkstra("A","E");
console.log(list.Dijkstra("A","E"));
