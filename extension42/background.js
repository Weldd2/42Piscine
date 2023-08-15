const UID = 'u-s4t2ud-4ca28be35e5d21241811c2e3cee93fa388c2840b602177e39cb07d8b0c65c489';
const SECRET = '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';

const API_URL = "https://api.intra.42.fr/v2/76/users";

function getToken() {
    return fetch('https://api.intra.42.fr/oauth/token', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
            grant_type: 'client_credentials',
            client_id: UID,
            client_secret: SECRET
        })
    })
    .then(response => response.json())
    .then(data => {
        if (data && data.access_token) {
            return data.access_token;
        } else {
            throw new Error("Failed to get access token");
        }
    });
}

let token = getToken();

fetch('https://api.intra.42.fr/v2/campus', {
        method: 'GET',
        headers: {
		'Authorization': `Bearer ${token}`,
        	'Content-Type': 'application/json'
        },
    })
    .then(response => response.json())
    .then(data => console.log(data))

