console.log("Worker Loaded");

self.onmessage = async function () {

    try {

        const response = await fetch("https://dummyjson.com/users");

        if (!response.ok) {
            throw new Error("API request failed");
        }

        const data = await response.json();

        self.postMessage({
            success: true,
            users: data.users  
        });

    } catch (err) {

        self.postMessage({
            success: false,
            message: "No users found"
        });

    }

};