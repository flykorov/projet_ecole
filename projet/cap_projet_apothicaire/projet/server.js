const express = require('express');
const router = express();
const { spawn } = require('child_process');
const port = 3000;

router.use(express.json());

router.use((req, res, next) => {    
    res.header('Access-Control-Allow-Origin', '*');
    res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
    next();
});


router.post('/execute', (req, res) => {
    console.log(req.body);
    matrice = req.body;

    const pythonProcess = spawn('python3', ['public/model.py', JSON.stringify(matrice)]);

    let Response = '';  // Variable

    pythonProcess.stdout.on('data', (data) => {
      Response = data.toString()

    });

    // Gestion des erreurs
    pythonProcess.stderr.on('data', (data) => {
      console.error(`Erreur Python : ${data}`);
    });

    // Gestion de la fin de l'exécution
    pythonProcess.on('close', (code) => {
      if (code !== 0) {
        console.error(`Le processus Python s'est terminé avec le code d'erreur ${code}`);
      }

      // Envoyer la réponse une seule fois après que toutes les données ont été reçues
      res.json({result: Response});
    });
});

router.listen(port, () => {
    console.log(`Server listening on port ${port}`);
});