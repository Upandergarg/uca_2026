const fields= [
    "First Name",
    "Last Name",
    "Email"
]

function generateForm(){

    document.getElementById("form").innerHTML= 
    fields.map(field => `
           <label>${field}</label>
                <input type="text">
                <br><br><br>
        `
    ).join("")
}

generateForm()