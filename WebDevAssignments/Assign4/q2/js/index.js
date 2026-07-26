const worker = new Worker("../js/worker.js");

const usersDiv = document.getElementById("users");

worker.postMessage("start");

worker.onmessage = function (event) {

    if (event.data.success) {

        const users = event.data.users;

        if (users.length === 0) {

            usersDiv.innerHTML = "No users found";
            return;

        }

        let output = "";

        users.forEach(user => {

            output +=  `FirstName = ${user.firstName}      
             ||       LastName = ${user.lastName}<br>`;

        });

        usersDiv.innerHTML = output;

    } else {

        usersDiv.innerHTML = event.data.message;

    }

};