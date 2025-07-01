# **What is a Tree in Data Structures?**

A **tree** is a hierarchical data structure consisting of nodes. It is used to represent relationships where data is organized in a parent-child manner. The tree is a non-linear structure that does not form cycles.

## **Key Characteristics of a Tree**

1. **Root Node**: The topmost node in the tree. Every tree has only one root.
2. **Child Nodes**: Nodes directly connected to another node as its descendants.
3. **Parent Node**: A node with one or more child nodes.
4. **Leaf Node**: Nodes that have no children (the terminal nodes).
5. **Edge**: A connection between one node and another.
6. **Height**: The length of the longest path from the root to any leaf.
7. **Depth**: The number of edges from the root to a given node.
8. **Subtree**: A tree formed by any node and its descendants.

---

## **Components in a Tree**

1. **Nodes**: Represent data.
2. **Edges**: Represent the connections between nodes.
3. **Root**: The starting node of the tree.
4. **Leaves**: Nodes with no children.
5. **Subtrees**: Smaller sections of the tree branching off from a parent.

---

## **Where are Trees Used?**

1. **Hierarchy Representation**:
    - File systems (e.g., folder structures on a computer).
    - Organizational charts.
    - HTML/DOM elements in web development.
2. **Searching and Sorting**:
    - Binary Search Trees (for efficient searching and insertion).
    - Heaps (for priority queues).
3. **Network Routing**:
    - Spanning trees in network protocols.
4. **AI and Game Development**:
    - Decision trees.
    - Minimax algorithms.

---

## **Tree Traversal Methods**

Traversal means visiting each node in the tree systematically. Common methods include:

### **1. Inorder Traversal**

- **Order**: **Left → Root → Right**
- Used in binary trees to retrieve elements in sorted order.
- **Example**:
    
    ```
    Tree Structure:
        2
       / \
      1   3
    
    Inorder Traversal: 1 → 2 → 3
    ```
    

### **2. Preorder Traversal**

- **Order**: **Root → Left → Right**
- Used to create a copy of the tree or for prefix expressions.
- **Example**:
    
    ```
    Tree Structure:
        2
       / \
      1   3
    
    Preorder Traversal: 2 → 1 → 3
    ```
    

### **3. Postorder Traversal**

- **Order**: **Left → Right → Root**
- Used for deleting nodes or for postfix expressions.
- **Example**:
    
    ```
    Tree Structure:
        2
       / \
      1   3
    
    Postorder Traversal: 1 → 3 → 2
    ```
    

---

## **Time Complexities of Operations in a Simple Tree**

### **1. Insertion**

- **Time Complexity**: O(n)
- In a general tree, you may need to traverse all nodes to find the correct location to insert.

### **2. Deletion**

- **Time Complexity**: O(n)
- Searching for the node to delete may require traversing the entire tree.

### **3. Traversal (Inorder, Preorder, Postorder)**

- **Time Complexity**: O(n)
- All nodes are visited once, so the time complexity is proportional to the number of nodes.

---

## **Summary Table of Operations**

| Operation   | Simple Tree Time Complexity | Explanation                                  |
|------------|----------------------------|----------------------------------------------|
| **Insertion** | O(n)                         | May traverse the whole tree to find position. |
| **Deletion**  | O(n)                         | Need to locate the node before deletion.    |
| **Traversal** | O(n)                         | Visits all nodes in a single traversal.     |


**Docker Commands**
### 📦 **Set up Docker APT repository**

```bash
sudo apt-get update
sudo apt-get install ca-certificates curl gnupg
```
### 📦 **Using Docker with BusyBox**

**Pull the BusyBox image:**

```bash
sudo docker pull busybox
```

**List images:**

```bash
sudo docker images
```

**Run BusyBox command:**

```bash
sudo docker run busybox echo "Hello from BusyBox"
```

**Manage containers:**

```bash
sudo docker ps
sudo docker ps -a
sudo docker start [container-id]
sudo docker stop [container-id]
sudo docker rm [container-id]
```

---

### 🌐 **Web App with Docker**

**Run a static website:**

```bash
sudo docker run -d -p 80:80 nginx
sudo docker run -d -p 8080:80 --name my-site nginx
```

**Run in detached mode:**

```bash
sudo docker run -d nginx
```

**Specify custom port:**

```bash
sudo docker run -d -p 8080:80 nginx
sudo docker run -d -p 8888:80 prakhar1989/static-site
```

**Stop the container:**

```bash
sudo docker stop [container-id]
```

---

### 🐳 **Creating Your Own Docker Image**

**Clone Flask App:**

```bash
git clone https://github.com/docker/awesome-compose.git
cd awesome-compose/flask
git clone https://github.com/prakhar1989/docker-compose.git

```

**Build the image:**

```bash
sudo docker build -t my-flask-app .
```

**Run the Flask app:**

```bash
sudo docker run -d -p 5000:5000 my-flask-app
sudo docker run -d -p 8888:5000 root/catnip
```

---

### 📤 **Docker Push**

**Login to Docker Hub:**

```bash
sudo docker login
```

**Tag the image:**

```bash
sudo docker tag my-flask-app yourusername/my-flask-app
```

**Push the image:**

```bash
sudo docker push yourusername/my-flask-app
```

---

### 🔐 **Securing Docker (OWASP Rules)**

#### Rule #2 – Run as non-root user

**Dockerfile:**

```dockerfile
FROM busybox
RUN adduser -D myuser
USER myuser
CMD ["sh"]
```

**Build the image:**

```bash
sudo docker build -t non-root-app .
```

**Run the container:**

```bash
sudo docker run -it non-root-app
```

**Verify it runs as non-root:**

```bash
id
```

---

#### Rule #3 – Drop capabilities

**Drop all and add only needed:**

```bash
sudo docker run -it --cap-drop=ALL --cap-add=NET_BIND_SERVICE nginx
```

**Test by dropping only a few:**

```bash
sudo docker run -it --cap-drop=SYS_ADMIN nginx
```

---

#### Rule #8 – Set filesystem to read-only

```bash
sudo docker run -it --read-only nginx
```
######**Jenkins Initial Setup** #####
### **1. Pre-requisites**

* **Java Installation:**
  Java must be installed before running Jenkins. If it's not installed, download and install it from:
  [https://www.oracle.com/java/technologies/downloads/#jdk21-windows](https://www.oracle.com/java/technologies/downloads/#jdk21-windows)

---

### **2. Download Jenkins WAR File**

* Download the `jenkins.war` file from Jenkins' official website to run Jenkins as a standalone application.

---

### **3. Start Jenkins Using WAR File**

* Open **Command Prompt**.
* Use `cd` to navigate to the directory containing `jenkins.war`.
* Run Jenkins with the command:

  ```bash
  java -jar jenkins.war
  ```

---

### **4. Access Jenkins in Browser**

* Go to: [http://localhost:8080](http://localhost:8080)
* Enter the initial admin password (found at `C:\Users\<UserName>\.jenkins\secrets\initialAdminPassword`).
* Select **Install Suggested Plugins**.
* Complete admin user setup.

---

### **5. Jenkins + Tomcat Setup**

* **Download Tomcat:**
  From [https://tomcat.apache.org/download-70.cgi](https://tomcat.apache.org/download-70.cgi)
* **Unzip Tomcat** and go to its `webapps` folder.
* Copy `jenkins.war` into the `webapps` directory.
* Start Tomcat and access Jenkins at:
  [http://localhost:8080/jenkins](http://localhost:8080/jenkins)

---

### **6. Verifying Java Installation**

* Confirm Java is installed by running:

  ```bash
  java -version
  ```
* Also verify the `JAVA_HOME` path.

---

### **7. Integrate Git with Jenkins**

* Go to:
  `Manage Jenkins` → `Plugin Manager` → `Available` tab
* Search for **Git Plugin** or **Git Push Plugin**.
* Install the plugin and restart Jenkins from:
  [http://localhost:8080/jenkins/restart](http://localhost:8080/jenkins/restart)

---

### **8. Create Freestyle Jenkins Job**

* From Jenkins dashboard:

  * Click **New Item** → select **Freestyle project**.
  * Configure build settings as per your requirement.

---

### **9. After Build Successful**

* Post-build actions like notifications, archiving artifacts, or deploying can be configured based on job success.



###**Jenkins Lab 14**###

## 🔹 **1. Start Jenkins**

If using Jenkins via `.war` file:

```bash
# Navigate to the folder where jenkins.war is located
cd ~/Downloads

# Start Jenkins on port 8080
java -jar jenkins.war
```

If installed via package manager on Linux:

```bash
# Start Jenkins service
sudo systemctl start jenkins

# Enable on boot
sudo systemctl enable jenkins

# Check status
sudo systemctl status jenkins
```

---

### 🔹 **2. Create a New File with Code**

```bash
# Create the Jenkinsfile
nano Jenkinsfile
```

Paste this basic pipeline:

```groovy
pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                echo 'Building the application...'
            }
        }
        stage('Test') {
            steps {
                echo 'Running unit tests...'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying the application...'
            }
        }
    }
}
```

---

### 🔹 **3. Create Pipeline (Jenkins GUI Setup)**

No terminal commands, but you'd:

* Go to `http://localhost:8080`
* Create a **new item > Pipeline**
* Under **Pipeline > Definition**, choose "Pipeline script from SCM" or paste the `Jenkinsfile` code directly.

---

### 🔹 **4. Validate URL**

```bash
# Open Jenkins in browser
xdg-open http://localhost:8080
# or manually go to
http://localhost:8080
```

---

### 🔹 **5. Post Build Actions in Jenkinsfile**

```groovy
post {
    always {
        echo 'This will always run'
    }
    success {
        echo 'This build was successful!'
    }
    failure {
        echo 'This build failed!'
    }
}
```

---

### 🔹 **6. Build Again (via GUI or trigger job)**

No command, but this could simulate a build trigger:

```bash
# Rebuild the job using Jenkins REST API (if using tokens)
curl -X POST http://localhost:8080/job/your-job-name/build \
  --user youruser:apitoken
```

---

### 🔹 **7. Define Conditionals for Stages**

```groovy
stage('Deploy to Production') {
    when {
        branch 'main'
    }
    steps {
        echo 'Deploying to Production...'
    }
}
```

---

### 🔹 **8. Environment Variables**

```groovy
environment {
    APP_VERSION = '1.0.2'
    DEPLOY_ENV = 'dev'
}

stages {
    stage('Info') {
        steps {
            echo "Version: ${env.APP_VERSION}"
            echo "Deploying to: ${env.DEPLOY_ENV}"
        }
    }
}
```

---

### 🔹 **9. Tools Attribute for Build Tools**

```groovy
pipeline {
    agent any
    tools {
        maven 'Maven 3.8.1'
        jdk 'JDK 11'
    }
    stages {
        stage('Build') {
            steps {
                sh 'mvn clean install'
            }
        }
    }
}
```

---

### 🔹 **10. Create `pom.xml`**

```bash
nano pom.xml
```

Paste the following:

```xml
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0
         http://maven.apache.org/xsd/maven-4.0.0.xsd">

    <modelVersion>4.0.0</modelVersion>

    <groupId>com.example</groupId>
    <artifactId>myapp</artifactId>
    <version>1.0-SNAPSHOT</version>

    <dependencies>
        <!-- Sample dependency -->
        <dependency>
            <groupId>junit</groupId>
            <artifactId>junit</artifactId>
            <version>4.13.2</version>
            <scope>test</scope>
        </dependency>
    </dependencies>

</project>
```

---

### 🔹 **11. Parameters in Jenkins**

```groovy
pipeline {
    agent any
    parameters {
        string(name: 'DEPLOY_ENV', defaultValue: 'staging', description: 'Target deployment environment')
        booleanParam(name: 'RUN_TESTS', defaultValue: true, description: 'Run unit tests?')
    }
    stages {
        stage('Show Params') {
            steps {
                echo "Deploying to: ${params.DEPLOY_ENV}"
                echo "Run tests: ${params.RUN_TESTS}"
            }
        }
    }
}
```

---

### 🔹 **12. Final Pipeline Combining Everything**

```groovy
pipeline {
    agent any
    tools {
        maven 'Maven 3.8.1'
    }

    environment {
        APP_VERSION = '1.0.0'
        DEPLOY_ENV = "${params.ENV}"
    }

    parameters {
        string(name: 'ENV', defaultValue: 'dev', description: 'Environment')
    }

    stages {
        stage('Build') {
            steps {
                sh 'mvn clean install'
            }
        }

        stage('Test') {
            when {
                expression { return params.ENV != 'prod' }
            }
            steps {
                sh 'mvn test'
            }
        }

        stage('Deploy') {
            steps {
                echo "Deploying to environment: ${params.ENV}"
            }
        }
    }

    post {
        success {
            echo 'Pipeline executed successfully.'
        }
        failure {
            echo 'Pipeline execution failed.'
        }
    }
}


