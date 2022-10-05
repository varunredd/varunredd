function cofeeName(name){
    alert("Preparing Coffee :"+name);
}
function prepare(callback){
    var name = prompt("What coffee do you need?");
    callback(name);
}
prepare(cofeeName);

var myPromise = new  Promise(function(resolve,reject){
    reject("Event Successful");
})
myPromise.then(function(text){
    console.log(text);
}).catch(function(e){
    console.log(e);
})