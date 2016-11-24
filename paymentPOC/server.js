var tco = new Twocheckout({
    sellerId: "901330209",
    privateKey: "3B7B912D-E606-4B93-BF3D-3C4A18F73A20",
    sandbox: true   
});

var params = {
    "merchantOrderId": "123",
    "token": "MWQyYTI0ZmUtNjhiOS00NTIxLTgwY2MtODc3MWRlNmZjY2Jh",
    "currency": "USD",
    "total": "10.00",
"name": "Demo Item", "price": "-9.99", "type": "product", "quantity": "1", "recurrence": "4 Year", "startupFee": "9.99", 
    "billingAddr": {
        "name": "Testing Tester",
        "addrLine1": "123 Test St",
        "city": "Columbus",
        "state": "Ohio",
        "zipCode": "43123",
        "country": "USA",
        "email": "example@2co.com",
        "phoneNumber": "5555555555"
    }
};

tco.checkout.authorize(params, function (error, data) {
    if (error) {
        console.log(error.message);
    } else {
        console.log(JSON.stringify(data));
    }
});

