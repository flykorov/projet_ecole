import os

# Répertoire racine du projet
ROOT_DIR = os.path.dirname(os.path.abspath(__file__))

# Répertoires principaux
DATA_DIR = os.path.join(ROOT_DIR, 'data')
UTILS_DIR = os.path.join(ROOT_DIR, 'utils')
INFERENCE_DIR = os.path.join(ROOT_DIR, 'inference_with_API')
TRAINING_DIR = os.path.join(ROOT_DIR, 'training_and_evaluation')