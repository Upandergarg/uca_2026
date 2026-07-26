//FIRST ATTEMPT ->
// console.log("Worker Loaded");

// self.onmessage = async (event) => {
//     console.log("Received:", event.data);

//     const response = await fetch(event.data);
//     const data = await response.json();

//     self.postMessage(data);
// };
// self.onmessage= async (data) =>{
//     await fetch(data.data)
//     .then((res) => res.json())
//     .then((json) => self.postMessage(json))
// }


self.onmessage = async function () {

    try {
console.log("starting web")
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok) {
            throw new Error("API Request Failed");
        }

        const users = await response.json();

        if (!users || users.length === 0) {
            throw new Error("No Users Found");
        }

        self.postMessage({
            success: true,
            users: users
        });

    } catch (err) {

        self.postMessage({
            success: false,
            message: err.message
        });

    }

};