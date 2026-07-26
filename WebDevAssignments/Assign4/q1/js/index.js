//FIRST ATTEMPT->

// const wr= new Worker("../js/worker.js")

// wr.postMessage("https://dummyapi.com/users");
// wr.onmessage= (data) => {
//     console.log(data.data);
// }


const worker = new Worker("../js/worker.js");

worker.postMessage("Start");
console.log("starting")

worker.onmessage = function (event) {
console.log("starting")
    if (event.data.success) {

        event.data.users.forEach(user => {

            console.log(
                `${user.name} - ${user.active ? "Active" : "Inactive"}`
            );
        });
    }
    else {

        console.error(event.data.message);

    }

};
