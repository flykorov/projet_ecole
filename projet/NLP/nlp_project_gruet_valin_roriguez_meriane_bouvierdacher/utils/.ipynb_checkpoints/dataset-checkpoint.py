"""
Module pour les datasets personnalisés.

Classes :
    - ToxicityDataset: Dataset PyTorch pour la détection de toxicité.
"""


import torch
from torch.utils.data import Dataset

class ToxicityDataset(Dataset):
    def __init__(self, df, target_columns):
        """
        Dataset personnalisé pour la détection de toxicité.
        :param df: Dataframe contenant les colonnes `input_ids`, `attention_mask` et les cibles.
        :param target_columns: Liste des colonnes de cibles (toxic, severe_toxic, etc.).
        """
        self.input_ids = df['input_ids'].tolist()
        self.attention_mask = df['attention_mask'].tolist()
        self.labels = df[target_columns].values

    def __len__(self):
        return len(self.input_ids)

    def __getitem__(self, idx):
        return {
            'input_ids': torch.tensor(self.input_ids[idx], dtype=torch.long),
            'attention_mask': torch.tensor(self.attention_mask[idx], dtype=torch.long),
            'labels': torch.tensor(self.labels[idx], dtype=torch.float)
        }