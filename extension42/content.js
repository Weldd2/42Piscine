// Ce code sera injecté dans chaque page visitée.
console.log('L\'extension "42 leaderboard" est active sur cette page.');

function getElementByXpath(path) {
	return document.evaluate(path, document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue;
}

function createDiv()
{
	// Créez un nouvel élément div
	let mainDiv = document.createElement('div');
	mainDiv.className = 'col-lg-4 col-md-6 col-xs-12 fixed-height';
	
	let containerDiv = document.createElement('div');
	containerDiv.className = 'container-inner-item boxed';
	containerDiv.setAttribute('data-turbolinks-scaffold', 'inside');
	containerDiv.style.overflow = 'auto';
	
	let titleH4 = document.createElement('h4');
	titleH4.className = 'profile-title';
	titleH4.textContent = 'Leaderboard';

	containerDiv.appendChild(titleH4);

	let verticalListDiv = document.createElement('div');
	verticalListDiv.className = 'vertical-list';
	containerDiv.appendChild(verticalListDiv);

	mainDiv.appendChild(containerDiv);

	return mainDiv;
}

function createLeaderBoard(leaderboardData) {
	let liste = document.createElement('ol');
	leaderboardData.forEach(student => {
	    let listeElem = document.createElement('li');
	    listeElem.innerText = `${student.name} ${student.experience}`; // Assurez-vous que le leaderboardData contient bien ces champs
	    liste.appendChild(listeElem);
	});
    
	return liste;
    }
    

    function displayLeaderboard(leaderboardData) {
	let row = getElementByXpath("/html/body/div[4]/div[2]/div/div[2]/div/div[2]/div");
    
	let containerDiv = createDiv();
    
	let liste = createLeaderBoard(leaderboardData);
    
	containerDiv.children[1].appendChild(liste); // Ajout à 'vertical-list' dans 'container-inner-item'
    
	row.appendChild(containerDiv);
    }
    

chrome.runtime.onMessage.addListener(function(request, sender, sendResponse) {
	if (request.message === "data_from_background") {
	    const leaderboardData = request.data;
	    displayLeaderboard(leaderboardData);
	}
    });
    



